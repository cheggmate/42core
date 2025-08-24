/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_set_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:07:49 by jotong            #+#    #+#             */
/*   Updated: 2025/08/24 23:28:23 by jotong           ###   ########.fr       */
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

int	set_phil_eat_time(t_phil *phil, long long new_time)
{
	pthread_mutex_lock(&phil->lock);
	phil->t_last_ate = new_time;
	pthread_mutex_unlock(&phil->lock);
	return (1);
}
