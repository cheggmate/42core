/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:07:20 by jotong            #+#    #+#             */
/*   Updated: 2025/08/24 23:52:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_all_arr(t_tab *tab)
{
	free(tab->threads);
	// free(tab->forks);
	if (tab->f_owners)
	{
		free(tab->f_owners);
		tab->f_owners = NULL;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void free_tab_everything(t_tab *tab)
{
	printf("calling free everything\n");
	if (!tab)
		return ;
	if (tab->forks)
	{
		destroy_forks(tab);
		free(tab->forks);
		tab->forks = NULL;
	}
	printf("free forks\n");
	if (tab->phils)
	{
		free(tab->phils);
		tab->phils = NULL;
	}
	destroy_other_mutexes(tab);
	printf("destroyed other mutexes\n");
	free_all_arr(tab);
	printf("freeed al arrs\n");
	return ;
}

void	free_phil_everything(t_phil *phil)
{
	pthread_mutex_destroy(&phil->lock);
}

