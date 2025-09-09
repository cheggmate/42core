/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_set_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:07:49 by jotong            #+#    #+#             */
/*   Updated: 2025/08/28 19:16:12 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_phil_state(t_phil *phil, char new_state)
{
	pthread_mutex_lock(&phil->lock);
	phil->state = new_state;
	pthread_mutex_unlock(&phil->lock);
	return (1);
}

int	set_phil_eat(t_phil *phil, long long new_time)
{
	pthread_mutex_lock(&phil->lock);
	phil->t_last_ate = new_time;
	phil->n_eat++;
	phil->state = 'e';
	pthread_mutex_unlock(&phil->lock);
	return (1);
}

int	set_stop_flag(t_tab *tab)
{
	pthread_mutex_lock(&tab->s_lock);
	tab->stop = 1;
	pthread_mutex_unlock(&tab->s_lock);
	return (1);
}
