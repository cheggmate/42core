/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/08/01 23:48:57 by jotong           ###   ########.fr       */
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
		result = pthread_mutex_lock(&phil->tab->forks[n]);
		if (result == 0)
		{
			printf("%lld %zu has taken a (left) fork\n", get_ts(), phil->n);
			result = pthread_mutex_lock(&phil->tab->forks[(n + 1) % n]);
			if (result == 0)
				printf("%lld %zu has taken a (right) fork\n", get_ts(), phil->n);	
		}
		else 													// remove before submitting
			write(2, strerror(result), strlen(strerror(result)));
	}
	else
	{
		result = pthread_mutex_lock(&phil->tab->forks[(n + 1) % n]);
		if (result == 0)
		{
			printf("%lld %zu has taken a (right) fork\n", get_ts(), phil->n);
			result = pthread_mutex_lock(&phil->tab->forks[n]);
			if (result == 0)
				printf("%lld %zu has taken a (left) fork\n", get_ts(), phil->n);	
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
		result = pthread_mutex_unlock(&phil->tab->forks[(n + 1) % n]);
		if (result == 0)
			result = pthread_mutex_unlock(&phil->tab->forks[n]);
	}
	else
	{
		result = pthread_mutex_unlock(&phil->tab->forks[n]);
		if (result == 0)
			result = pthread_mutex_unlock(&phil->tab->forks[(n + 1) % n]);
	}
}
