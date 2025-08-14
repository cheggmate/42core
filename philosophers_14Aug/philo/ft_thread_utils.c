/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:50:38 by jotong            #+#    #+#             */
/*   Updated: 2025/08/14 22:37:26 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_tab *tab)
{
	int			num;
	int			i;
	int			result;

	i = -1;
	result = 0;
	if (!tab)
		return (-1);
	num = tab->p_total;
	while (++i < num)
	{
		result = pthread_create(&tab->threads[i], NULL, keep_philos_alive, &tab->phils[i]);
		if (result != 0)
			return (-1);
	}
	return (0);	
}

int	join_threads(t_tab *tab)
{
	int	i;

	i = -1;
	while(++i < tab->p_total)
	{
		pthread_join(tab->threads[i], NULL);
		bar_wait(&tab->start_blk);
	}
	return (0);
}

int	lock_stop_mutex(t_tab *tab)
{
	pthread_mutex_lock(&tab->s_lock);
	return (0);
}

void	bar_init(t_bar *s_block, int count)
{
	pthread_mutex_init(&s_block->mutex, NULL);
	pthread_cond_init(&s_block->cond, NULL);
	s_block->count = count;
	s_block->p_count = count;
}

void	bar_wait(t_bar *s_block)
{
	pthread_mutex_lock(&s_block->mutex);
	s_block->count--;

	if (s_block->count == 0)
	{
		s_block->count = s_block->p_count;
		pthread_cond_broadcast(&s_block->cond);
	}
	else
	{
		pthread_cond_wait(&s_block->cond, &s_block->mutex);
	}
	pthread_mutex_unlock(&s_block->mutex);
}
