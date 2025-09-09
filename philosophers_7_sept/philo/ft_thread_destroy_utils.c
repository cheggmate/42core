/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_destroy_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:29:42 by jotong            #+#    #+#             */
/*   Updated: 2025/08/28 18:19:17 by jotong           ###   ########.fr       */
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
				int err;
				// printf("starting to detach threads\n");
				err = pthread_detach(tab->threads[i]);
				if (err != 0)
					printf("error detaching thread %d\n", i);
				// printf("detached thread %d\n", i);
			}
		}
		// printf("done detaching\n");
		return (0);
	}
}

int	destroy_other_mutexes(t_tab *tab)
{
	if (!tab)
		return (0);
	pthread_mutex_destroy(&tab->s_lock);
	pthread_mutex_destroy(&tab->print);
	// printf("destroy s_lock and print mutex\n");
	tab->fork_inited = 0;
	pthread_cond_destroy(&tab->start_blk.cond);
	pthread_mutex_destroy(&tab->start_blk.mutex);
	// printf("destroy pthread mutexes\n");
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
	pthread_mutex_destroy(&phil->lock);
	return (0);
}
