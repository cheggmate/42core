/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:07:20 by jotong            #+#    #+#             */
/*   Updated: 2025/08/17 22:21:05 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_all_arr(t_tab *tab)
{
	free(tab->threads);
	free(tab->forks);
	free(tab);
	if (tab->f_owners)
		free(tab->f_owners);
	tab->forks = NULL;
	tab->phils = NULL;
	tab->f_owners = NULL;
	tab = NULL;
}

void free_everything(t_tab *tab)
{
	printf("calling free everything\n");
	if (!tab)
		return ;
	if (tab->forks)
	{
		destroy_forks(tab);
		free(tab->forks);
	}
	if(tab->phils)
	{
		close_threads(tab);
		free(tab->phils);
		// printf("freed tab->phils\n");
	}
	destroy_other_mutexes(tab);
	printf("destroyed other mutexes\n");
	free_all_arr(tab);
	// free(tab->threads);
	// free(tab->forks);
	// free(tab);
	// tab->forks = NULL;
	// tab->phils = NULL;
	// tab = NULL;
}
