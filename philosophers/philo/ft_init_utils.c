/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:55:34 by jotong            #+#    #+#             */
/*   Updated: 2025/08/01 23:58:21 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	init_frk(t_tab **tab, t_pool *mem_p)
// {
// 	(*tab)->forks = alloc_mem(mem_p, sizeof(t_frk));
// 	if (!((*tab)->forks))
// 	{
// 		free_everything(mem_p, tab);
// 		return (1);
// 	}
// 	return (0);	
// }

// static int	init_phil(t_tab **tab, t_pool *mem_p)
// {
// 	(*tab)->phils = alloc_mem(mem_p, sizeof (t_phil));
// 	if (!init_frk(tab, mem_p) || !((*tab)->phils))
// 	{
// 		free_everything(mem_p, tab);
// 		return (1);
// 	}
// 	return (0);
// }

// int	init_tab(t_tab **tab, t_pool *mem_p)
// {
// 	*tab = alloc_mem(mem_p, sizeof(t_tab));
// 	if (!init_phil(tab, mem_p) || !(*tab))
// 	{
// 		free_everything(mem_p, tab);
// 		return (1);
// 	}
// 	return (0);
// }

// static int	init_frk(t_tab *tab)
// {
// 	// (*tab)->forks = alloc_mem(sizeof(t_frk));
// 	tab->forks = ft_calloc(tab->p_total, sizeof(pthread_mutex_t));
// 	if (!(tab->forks))
// 	{
// 		free_everything(tab);
// 		return (-1);
// 	}
// 	return (0);	
// }

static int	init_phil(t_tab *tab)
{
	size_t	i;

	i = -1;
	// tab->phils = alloc_mem(sizeof(t_phil));
	tab->phils = ft_calloc(tab->p_total, sizeof(t_phil));
	if (!tab->phils)
	{
		free_everything(tab);
		return (-1);
	}
	while (++i < tab->p_total)
	{
		tab->phils[i].eat_count = 0;
		tab->phils[i].t_last_ate = get_time();
		tab->phils[i].tb = tab;
		tab->phils[i].state = 'z';
		tab->phils[i].thread = tab->threads[i];
	}
	return (0);
}

int	init_tab(t_tab *tab)
{
	// tab = alloc_mem(sizeof(t_tab));
	tab = ft_calloc(1, sizeof(t_tab));
	tab->threads = (pthread_t *)ft_calloc(tab->p_total + 1, sizeof(pthread_t)); // creating one extra thread for monitoring
	if (!init_phil(tab) || !tab)
	{
		free_everything(tab);
		return (-1);
	}
	return (0);
}
