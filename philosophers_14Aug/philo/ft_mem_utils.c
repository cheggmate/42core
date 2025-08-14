/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:07:20 by jotong            #+#    #+#             */
/*   Updated: 2025/08/13 21:36:36 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_everything(t_tab *tab)
{
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
		printf("freed tab->phils\n");
	}
	destroy_other_mutexes(tab);
	printf("destroyed other mutexes\n");
	free(tab->threads);
	free(tab->forks);
	free(tab);
	tab->forks = NULL;
	tab->phils = NULL;
	tab = NULL;
}
