/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_destroy_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:29:42 by jotong            #+#    #+#             */
/*   Updated: 2025/08/03 23:42:41 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	close_threads(t_tab **tab)
{
	pthread_t	*t_ptr;
	int			i;

	i = -1;
	if (!(*tab))
		return (-1);
	else
	{
		while (++i < (*tab)->p_total + 1)
		{
			t_ptr = (*tab)->threads[i];
			if (t_ptr)
			{
				pthread_detatch(t_ptr);
				pthread_mutex_destroy(t_ptr);
				t_ptr = NULL;
				if (i < (*tab)->p_total)
					(*tab)->phils[i].thread = NULL;
			}
		}
		return (0);
	}
}

int	destroy_forks(t_tab **tab)
{
	int	i;

	i = -1;
	if (!(*tab)->forks)
		return (-1);
	while (++i < (*tab)->p_total)
		pthread_mutex_destroy(&(*tab)->forks[i]);
}

int	unlock_stop_mutex(t_tab *tab)
{
	pthread_mutex_unlock(&tab->s_lock);
	return (0);
}
