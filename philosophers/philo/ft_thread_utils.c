/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:50:38 by jotong            #+#    #+#             */
/*   Updated: 2025/07/30 00:07:28 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_tab **tab)
{
	pthread_t	*t_ptr;
	size_t		num;
	size_t		i;

	i = -1;
	if (!(*tab))
		return (-1);
	num = (*tab)->p_total;
	while (++i < num)
	{
		t_ptr = (*tab)->threads[num];
		if (!t_ptr || !(*tab)->phils[num])
			pthread_create(&t_ptr, NULL, keep_philos_alive, &(*tab)->phils[i]);
		else
			return (-1);
	}
	return (0);	
}

int	close_threads(t_tab **tab)
{
	pthread_t	*t_ptr;
	size_t		i;

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
				t_ptr = NULL;
				if (i < (*tab)->p_total)
					(*tab)->phils[i]->thread = NULL;
			}
		}
		return (0);
	}
}

int	destroy_forks(t_tab **tab)
{
	size_t	i;

	i = -1;
	if (!(*tab)->forks)
		return (-1);
	while (++i < (*tab)->p_total)
		pthread_mutex_destroy(&(*tab)->forks[i]);
}
