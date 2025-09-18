/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:50:38 by jotong            #+#    #+#             */
/*   Updated: 2025/09/17 20:05:39 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_tab *tab)
{
	int			num;
	int			i;

	i = -1;
	if (!tab)
		return (-1);
	num = tab->p_total;
	if (pthread_create(&tab->threads[num], NULL, monitoring, tab) != 0)
	{
		while (--i > 0)
			pthread_detach(tab->threads[i]);
		return (-1);
	}
	while (++i < num)
	{
		if (pthread_create(&tab->threads[i], NULL,
				keep_philos_alive, &tab->phils[i]) != 0)
			{
				while (--i > 0)
					pthread_detach(tab->threads[i]);
				return (-1);
			}
	}
	// if (pthread_create(&tab->threads[num], NULL, monitoring, tab) != 0)
	// {
	// 	while (--i > 0)
	// 		pthread_detach(tab->threads[i]);
	// 	return (-1);
	// }
	return (0);
}

int	join_threads(t_tab *tab)
{
	int	i;

	i = -1;
	while (tab->eat_count != 0 && ++i < tab->p_total)
		pthread_join(tab->threads[i], NULL);
	pthread_join(tab->threads[tab->p_total], NULL);
	return (0);
}

// int	leave_thread(t_phil *phil)
// {
// 	int	result;
	
// 	result = pthread_mutex_lock(&phil->tb->s_lock);
// 	if (result == 0)
// 	{
// 		// TODO
// 	}
// 	pthread_mutex_lock(&phil->tb->s_lock);
// }
