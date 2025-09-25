/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_destroy_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:29:42 by jotong            #+#    #+#             */
/*   Updated: 2025/09/25 21:38:39 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	close_threads(t_tab *tab)
{
	int	i;
	int	err;

	i = -1;
	err = 0;
	if (!tab)
		return (-1);
	while (++i < tab->p_total + 1)
	{
		err = pthread_detach(tab->threads[i]);
		if (err != 0)
			return (-1);
	}
	return (0);
}

int	destroy_other_mutexes(t_tab *tab)
{
	if (!tab)
		return (0);
	pthread_mutex_destroy(&tab->s_lock);
	pthread_mutex_destroy(&tab->print);
	tab->fork_inited = 0;
	pthread_mutex_destroy(&tab->start);
	pthread_mutex_destroy(&tab->t_lock);
	return (0);
}

int	destroy_forks(t_tab *tab)
{
	int	i;

	i = -1;
	if (!tab->forks)
		return (-1);
	while (++i < tab->p_total)
		pthread_mutex_destroy(&tab->forks[i]);
	return (0);
}

int	destroy_phils(t_phil *phil)
{
	if (!phil)
		return (-1);
	pthread_mutex_destroy(phil->lock);
	return (0);
}
