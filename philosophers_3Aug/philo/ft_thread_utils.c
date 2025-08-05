/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:50:38 by jotong            #+#    #+#             */
/*   Updated: 2025/08/06 00:19:05 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_tab **tab)
{
	int			num;
	int			i;
	int			result;

	i = -1;
	result = 0;
	if (!(*tab))
		return (-1);
	num = (*tab)->p_total;
	while (++i < num)
	{
		printf("i = %d\n", i);
		result = pthread_create(&(*tab)->threads[i], NULL, keep_philos_alive, &(*tab)->phils[i]);
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
		pthread_join(tab->threads[i], NULL);
	return (0);
}

int	lock_stop_mutex(t_tab *tab)
{
	pthread_mutex_lock(&tab->s_lock);
	return (0);
}
