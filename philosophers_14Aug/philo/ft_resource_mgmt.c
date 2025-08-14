/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/08/14 13:22:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up_frks(t_phil *phil)
{
	int	result;
	int	n;

	n = phil->n;
	if (n % 2 == 1)
	{
		result = pthread_mutex_lock(&phil->tb->forks[n]);
		if (result == 0)
		{
			phil->state = 'f';
			print_safely(phil);
			result = pthread_mutex_lock(&phil->tb->forks[(n + 1) % n]);
			if (result == 0)
				print_safely(phil);
		}
		else 													// remove before submitting
		{
			write(2, strerror(result), strlen(strerror(result)));
			return (1);
		}
	}
	else
	{
	
		int fork_r;

		if (n != phil->tb->p_total-1)
			fork_r = n + 1;
		else
			fork_r = 0;
		result = pthread_mutex_lock(&phil->tb->forks[fork_r]);
		if (result == 0)
		{
			phil->state = 'f';
			print_safely(phil);
			result = pthread_mutex_lock(&phil->tb->forks[n]);
			if (result == 0)
				print_safely(phil);	
		}
		else
		{
			write(2, strerror(result), strlen(strerror(result))); // remove before submitting
			return (1);
		}
	}
	return (0);
}

int	put_down_frks(t_phil * phil)
{
	int		result;
	size_t	n;

	result = 0;
	n = phil->n;
	if (phil->n % 2 == 1)
	{
		result = pthread_mutex_unlock(&phil->tb->forks[(n + 1) % n]);
		if (result == 0)
			result = pthread_mutex_unlock(&phil->tb->forks[n]);
	}
	else
	{
		result = pthread_mutex_unlock(&phil->tb->forks[n]);
		if (result == 0)
			result = pthread_mutex_unlock(&phil->tb->forks[(n + 1) % n]);
	}
	return (0);
}
