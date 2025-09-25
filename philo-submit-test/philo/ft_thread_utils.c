/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:50:38 by jotong            #+#    #+#             */
/*   Updated: 2025/09/25 22:09:12 by jotong           ###   ########.fr       */
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
	num = get_ptotal(tab);
	if (pthread_create(&tab->threads[num], NULL, monitoring, tab) != 0)
	{
		pthread_detach(tab->threads[num]);
		return (-1);
	}
	while (++i < num)
	{
		if (pthread_create(&tab->threads[i], NULL,
				keep_philos_alive, &tab->phils[i]) != 0)
		{
			while (i-- > 0)
				pthread_detach(tab->threads[i]);
			return (-1);
		}
	}
	return (0);
}

int	join_threads(t_tab *tab)
{
	int	i;
	int	result;

	i = -1;
	result = pthread_join(tab->threads[get_ptotal(tab)], NULL);
	if (result != 0)
		return (-1);
	while (++i < get_ptotal(tab))
	{
		result = pthread_join(tab->threads[i], NULL);
		if (result != 0)
			return (-1);
	}
	return (0);
}
