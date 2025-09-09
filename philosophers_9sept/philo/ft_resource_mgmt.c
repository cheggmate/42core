/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/09/09 21:39:07 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up_frks(t_phil *phil)
{
	int	n;
	int fork_r;

	n = phil->n;
	if (phil->tb->p_total % 2 == 1 && n == phil->tb->p_total - 1 && get_phil_eat(phil) == 0)	// odd number of philos and this is the last phil
		sleep_safely(1);
	if (n != phil->tb->p_total-1)
		fork_r = n + 1;
	else
		fork_r = 0;
	if (check_phil_state(phil, 'd') == 0)
		return (-1);
	if (n % 2 == 1)
	{
		if(pthread_mutex_lock(&phil->tb->forks[fork_r]) != 0)
			return (-1);
		phil->tb->f_owners[fork_r] = n;
		set_phil_state(phil, 'f');
		print_safely(phil);
		if(pthread_mutex_lock(&phil->tb->forks[n]) ==  0)
		{
			// printf("time elapsed between fork pickup = %lld\n", get_time() - fork1);
			phil->tb->f_owners[n] = n;
			print_safely(phil);
		}
		else
			put_down_frks(phil);
	}
	else
	{
		if (pthread_mutex_lock(&phil->tb->forks[n]) == 0)
		{
			phil->tb->f_owners[n] = n;
			set_phil_state(phil, 'f');
			print_safely(phil);
			if ((n != 0 && phil->tb->p_total == 1) && pthread_mutex_lock(&phil->tb->forks[fork_r]) == 0)
			{
				phil->tb->f_owners[fork_r] = n;
				print_safely(phil);
			}
			else
				put_down_frks(phil);
			if (n == 0 && phil->tb->p_total == 1)	// TODO: I CHANGED THIS
			{
				sleep_safely(phil->tb->t_die);
				return (-1);
			}
		}
	}
	return (0);
}

int	put_down_frks(t_phil * phil)
{
	int	n;
	int	i;

	i = -1;
	n = phil->n;
	// printf("put down forks called\n");
	while (++i < phil->tb->p_total)
	{
		if (phil->tb->f_owners[i] == n)
		{
			phil->tb->f_owners[i] = -1;
			pthread_mutex_unlock(&phil->tb->forks[i]);
		}
	}
	return (0);
}
