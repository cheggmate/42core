/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:07:20 by jotong            #+#    #+#             */
/*   Updated: 2025/09/17 20:38:22 by jotong           ###   ########.fr       */
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


void	free_tab_everything(t_tab *tab)
{
	int	i;
	i = -1;
	if (!tab)
		return ;
	if (tab->forks)
	{
		destroy_forks(tab);
		free(tab->forks);
	}
	if (tab->phils)
	{
		while (++i < tab->p_total)
			free(tab->phils[i].lock);
		free(tab->phils);
		tab->phils = NULL;
	}
	destroy_other_mutexes(tab);
	free_all_arr(tab);
}

void	free_phil_everything(t_phil *phil)
{
	pthread_mutex_destroy(phil->lock);
}
