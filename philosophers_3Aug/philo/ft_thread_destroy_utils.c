/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_destroy_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:29:42 by jotong            #+#    #+#             */
/*   Updated: 2025/08/05 00:09:39 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	close_threads(t_tab *tab)
{
	// pthread_t	t_ptr;
	int			i;

	i = -1;
	if (!tab)
		return (-1);
	else
	{
		while (++i < tab->p_total + 1)
		{
			if (tab->threads[i])
			{
				pthread_detach(tab->threads[i]);
				tab->threads[i] = NULL;
				if (i < tab->p_total)
					tab->phils[i].thread = NULL;
				printf("detached thread %d\n", i);
			}
		}
		printf("done detaching\n");
		return (0);
	}
}

int	destroy_other_mutexes(t_tab *tab)
{
	pthread_mutex_destroy(&tab->s_lock);
	printf("destroyed s_lock\n");
	pthread_mutex_destroy(&tab->print);
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

int	unlock_stop_mutex(t_tab *tab)
{
	pthread_mutex_unlock(&tab->s_lock);
	return (0);
}
