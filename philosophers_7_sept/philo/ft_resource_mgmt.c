/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/08/28 23:46:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up_frks(t_phil *phil)
{
	int	result;
	int	n;
	int fork_r;

	n = phil->n;
	if (phil->tb->p_total % 2 == 1 && n == phil->tb->p_total - 1 && get_phil_eat(phil) == 0)	// odd number of philos and this is the last phil
		sleep_safely(1);
	if (n != phil->tb->p_total-1)
		fork_r = n + 1;
	else
		fork_r = 0;
	if (phil->state == 'd')
		return (-1);
	if (n % 2 == 1)
	{
		result = pthread_mutex_lock(&phil->tb->forks[fork_r]);
		if (result == 0)
		{
			// long long	fork1 = get_time();
			phil->tb->f_owners[fork_r] = n;
			phil->state = 'f';
			print_safely(phil);
			result = pthread_mutex_lock(&phil->tb->forks[n]);
			if (result == 0)
			{
				// printf("time elapsed between fork pickup = %lld\n", get_time() - fork1);
				phil->tb->f_owners[n] = n;
				print_safely(phil);
			}
			else
				put_down_frks(phil);
		}
		else 													// remove before submitting
		{
			write(2, strerror(result), strlen(strerror(result)));
			return (1);
		}
	}
	else
	{
		result = pthread_mutex_lock(&phil->tb->forks[n]);
		if (result == 0)
		{
			phil->tb->f_owners[n] = n;
			phil->state = 'f';
			print_safely(phil);
			result = pthread_mutex_lock(&phil->tb->forks[fork_r]);
			if (result == 0)
			{
				phil->tb->f_owners[fork_r] = n;
				print_safely(phil);
			}
			else
				put_down_frks(phil);
		}
		else													 // remove before submitting
		{
			write(2, strerror(result), strlen(strerror(result)));
			return (1);
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
	while (++i < phil->tb->p_total)
	{
		if (phil->tb->f_owners[i] == n)
		{
			pthread_mutex_unlock(&phil->tb->forks[i]);
			phil->tb->f_owners[i] = -1;
		}
	}
	return (0);
}
