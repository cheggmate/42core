/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:50:38 by jotong            #+#    #+#             */
/*   Updated: 2025/09/18 23:10:44 by jotong           ###   ########.fr       */
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
				while (i > 0)
				{
					pthread_detach(tab->threads[i]);
					i-- ;
				}
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
	int	result;

	i = -1;
	result = pthread_join(tab->threads[tab->p_total], NULL);
	fprintf(stderr, "result: %d\n", result);
	if (result != 0)
		return (-1);
	while (++i < tab->p_total)
	{
		result = pthread_join(tab->threads[i], NULL);
		fprintf(stderr, "result (philo): %d\n", result);
		if (result != 0)
			return (-1);
	}
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
