/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:55:34 by jotong            #+#    #+#             */
/*   Updated: 2025/08/19 23:19:07 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_tab **tab)
{
	int i;
	int	result;

	i = -1;
	(*tab)->forks = ft_calloc((*tab)->p_total, sizeof(pthread_mutex_t));
	(*tab)->f_owners = ft_calloc((*tab)->p_total, sizeof(int));
	if (!(*tab)->forks || !(*tab)->f_owners)
	{
		free_everything(*tab);
		return (-1);
	}
	while (++i < (*tab)->p_total)
	{
		result = pthread_mutex_init(&(*tab)->forks[i], NULL);
		(*tab)->fork_inited = i;
		(*tab)->f_owners[i] = -1;
		if (result == -1)
		{
			free_everything(*tab);
			return (-1);
		}	
	}
	return (0);
}

static int	init_phil(t_tab **tab)
{
	int	i;

	i = -1;
	(*tab)->phils = (t_phil *)ft_calloc((*tab)->p_total, sizeof(t_phil));
	if (!(*tab)->phils)
	{
		free_everything((*tab));
		return (-1);
	}
	while (++i < (*tab)->p_total)
	{
		(*tab)->phils[i].n_eat = 0;
		(*tab)->phils[i].t_last_ate = get_time();
		(*tab)->phils[i].tb = (*tab);
		(*tab)->phils[i].n = i;
		(*tab)->phils[i].state = 'z';
	}
	return (0);
}

int	init_tab(t_tab **tab, int argc, char **argv)
{
	(*tab) = ft_calloc(1, sizeof(t_tab));
	(*tab)->threads = (pthread_t *)ft_calloc((*tab)->p_total + 1, sizeof(pthread_t)); // creating one extra thread for monitoring
	if (!(*tab))
	{
		free_everything((*tab));
		return (-1);
	}
	if (copy_values_into_vars(argc, argv, tab) == -1 || init_forks(tab) == -1 || init_phil(tab) != 0)
	{
		free_everything((*tab));
		return (-1);
	}
	bar_init(&(*tab)->start_blk, (*tab)->p_total + 1);
	return (0);
}
