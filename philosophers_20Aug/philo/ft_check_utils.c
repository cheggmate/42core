/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:04:26 by jotong            #+#    #+#             */
/*   Updated: 2025/08/24 23:27:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_phil_state(t_phil *phil, char s)
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
