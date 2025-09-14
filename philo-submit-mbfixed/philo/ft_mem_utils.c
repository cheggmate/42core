/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:07:20 by jotong            #+#    #+#             */
/*   Updated: 2025/09/14 19:21:32 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_all_arr(t_tab *tab)
{
	free(tab->threads);
	if (tab->f_owners)
		free(tab->f_owners);
	if (tab)
		free(tab);
}

// static int	phils_have_not_died(t_tab *tab)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < tab->p_total)
// 	{
// 		if (check_phil_state(&tab->phils[i], 'd') == 0)
// 			return (0);
// 	}
// 	return (1);
// }

void	free_tab_everything(t_tab *tab)
{
	if (!tab)
		return ;
	// while (!phils_have_not_died(tab))
	// 	sleep_safely(100);
	if (tab->forks)
	{
		destroy_forks(tab);
		free(tab->forks);
	}
	if (tab->phils)
		free(tab->phils);
	destroy_other_mutexes(tab);
	free_all_arr(tab);
	return ;
}

void	free_phil_everything(t_phil *phil)
{
	pthread_mutex_destroy(&phil->lock);
}
