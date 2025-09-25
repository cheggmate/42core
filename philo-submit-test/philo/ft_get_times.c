/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:26:11 by jotong            #+#    #+#             */
/*   Updated: 2025/09/25 22:00:25 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_t(t_tab *tab, char action)
{
	long long time;

	pthread_mutex_lock(&tab->t_lock);
	if (action == 'e')
		time = tab->t_eat;
	else if (action == 's')
		time = tab->t_slp;
	else if (action == 'd')
		time = tab->t_die;
	else
		time = 0;
	pthread_mutex_unlock(&tab->t_lock);
	return (time);	
}

int get_ptotal(t_tab *tab)
{
	int	tot;

	tot = 0;
	pthread_mutex_lock(&tab->t_lock);
	tot = tab->p_total;
	pthread_mutex_unlock(&tab->t_lock);
	return (tot);
}

int	get_eat_count(t_tab *tab)
{
	int	count;

	count = 0;
	pthread_mutex_lock(&tab->t_lock);
	count = tab->eat_count;
	pthread_mutex_unlock(&tab->t_lock);
	return (count);
}
