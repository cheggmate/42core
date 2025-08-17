/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/08/18 00:30:17 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up_frks(t_phil *phil)
{
	int	result;
	int	n;
	int fork_r;

	n = phil->n;
	if (n != phil->tb->p_total-1)
		fork_r = n + 1;
	else
		fork_r = 0;
	if (phil->state == 'd')
		return (-1);
	if (n % 2 == 1)
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
		else 													// remove before submitting
		{
			write(2, strerror(result), strlen(strerror(result)));
			return (1);
		}
	}
	else if (phil->tb->p_total != 3)	// TODO: Update the case where p_total = 3 and n = 2( third philo, make him wait 2x)
	{
		result = pthread_mutex_lock(&phil->tb->forks[fork_r]);
		if (result == 0)
		{
			phil->tb->f_owners[fork_r] = n;
			phil->state = 'f';
			print_safely(phil);
			if (phil->tb->p_total == 1)
			{
				sleep_safely(phil->tb->t_die);
				philo_died(phil);
				put_down_frks(phil);
			}
			else
			{
				result = pthread_mutex_lock(&phil->tb->forks[n]);
				if (result == 0)
				{
					phil->tb->f_owners[n] = n;
					print_safely(phil);
				}
				else
					put_down_frks(phil);
			}
		}
		else													 // remove before submitting
		{
			write(2, strerror(result), strlen(strerror(result)));
			return (1);
		}
	}
	else
	{
		sleep_safely(2 * phil->tb->t_eat);
		// usleep(2 * phil->tb->t_eat * 1000 - 1);
		result = pthread_mutex_lock(&phil->tb->forks[fork_r]);
		if (result == 0)
		{
			phil->tb->f_owners[fork_r] = n;
			phil->state = 'f';
			print_safely(phil);
			result = pthread_mutex_lock(&phil->tb->forks[n]);
			if (result == 0)
			{
				phil->tb->f_owners[n] = n;
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
	int	result;
	int	n;
	int	i;
	// int fork_r;

	i = -1;
	n = phil->n;
	// if (n != phil->tb->p_total-1)
	// 	fork_r = n + 1;
	// else
	// 	fork_r = 0;
	result = 0;
	n = phil->n;
	while (++i < n)
	{
		if (phil->tb->f_owners[i] == n)
			result = pthread_mutex_unlock(&phil->tb->forks[i]);
		if (result == 0)
			phil->tb->f_owners[i] = -1;
	}
	// if (phil->n % 2 == 1)
	// {
	// 	result = pthread_mutex_unlock(&phil->tb->forks[fork_r]);
	// 	if (result == 0)
	// 		result = pthread_mutex_unlock(&phil->tb->forks[n]);
	// }
	// else
	// {
	// 	result = pthread_mutex_unlock(&phil->tb->forks[n]);
	// 	if (result == 0)
	// 		result = pthread_mutex_unlock(&phil->tb->forks[fork_r]);
	// }
	return (0);
}
