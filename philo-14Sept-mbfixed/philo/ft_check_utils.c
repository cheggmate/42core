/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:04:26 by jotong            #+#    #+#             */
/*   Updated: 2025/09/14 15:33:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_phil_state(t_phil *phil, unsigned char s)
{
	pthread_mutex_lock(&phil->lock);
	if (phil->state == s)
	{
		pthread_mutex_unlock(&phil->lock);
		return (1);
	}
	pthread_mutex_unlock(&phil->lock);
	return (0);
}

int	check_stop_set(t_tab *tab)
{
	pthread_mutex_lock(&tab->s_lock);
	if (tab->stop == 1)
	{
		pthread_mutex_unlock(&tab->s_lock);
		return (1);
	}
	pthread_mutex_unlock(&tab->s_lock);
	return (0);
}

int	get_phil_eat(t_phil *phil)
{
	int	eat_count;

	eat_count = 0;
	pthread_mutex_lock(&phil->lock);
	eat_count = phil->n_eat;
	pthread_mutex_unlock(&phil->lock);
	return (eat_count);
}

long long	get_time_since_ate(t_phil *phil)
{
	long long	t;

	pthread_mutex_lock(&phil->lock);
	t = get_time() - phil->t_last_ate;
	pthread_mutex_unlock(&phil->lock);
	return (t);
}
