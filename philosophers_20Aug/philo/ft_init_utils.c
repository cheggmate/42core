/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:55:34 by jotong            #+#    #+#             */
/*   Updated: 2025/08/24 23:26:27 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_tab **tab)
{
	int i;
	int	result;

	i = -1;
	printf("initing forks\n");
	(*tab)->forks = ft_calloc((*tab)->p_total, sizeof(pthread_mutex_t));
	(*tab)->f_owners = ft_calloc((*tab)->p_total, sizeof(int));
	if (!(*tab)->forks || !(*tab)->f_owners)
	{
		free((*tab)->forks);
		free((*tab)->f_owners);
		(*tab)->forks = NULL;
		(*tab)->f_owners = NULL;
		return (-1);
	}
	printf("initing forks mutexes\n");
	while (++i < (*tab)->p_total)
	{
		result = pthread_mutex_init(&(*tab)->forks[i], NULL);
		(*tab)->fork_inited = i;
		(*tab)->f_owners[i] = -1;
		if (result == -1)
		{
			destroy_forks(*tab);
			return (-1);
		}	
	}
	return (0);
}

static int	init_phil(t_tab **tab)
{
	int	i;

	i = -1;
	printf("init phil\n");
	(*tab)->phils = (t_phil *)ft_calloc((*tab)->p_total, sizeof(t_phil));
	if (!(*tab)->phils)
		return (-1);
	while (++i < (*tab)->p_total)
	{
		printf("initing phil[%d]\n", i);
		(*tab)->phils[i].n_eat = 0;
		(*tab)->phils[i].t_last_ate = get_time();
		(*tab)->phils[i].tb = (*tab);
		(*tab)->phils[i].n = i;
		if (pthread_mutex_init(&(*tab)->phils[i].lock, NULL) == -1
			 || pthread_mutex_init(&(*tab)->phils[i].lock, NULL) == -1)
		{
			free((*tab)->phils);
			(*tab)->phils = NULL;
			return (-1);
		}
		(*tab)->phils[i].state = 'z';
	}
	return (0);
}

int	init_tab(t_tab **tab, int argc, char **argv)
{
	(*tab) = ft_calloc(1, sizeof(t_tab));
	printf("calloced tab\n");
	if (!(*tab))
	{
		free_tab_everything((*tab));
		return (-1);
	}
	if (copy_values_into_vars(argc, argv, tab) == -1 || init_forks(tab) == -1 || init_phil(tab) == -1)
	{
		free_tab_everything((*tab));
		return (-1);
	}
	printf("done coping values into vars\n");
	(*tab)->threads = (pthread_t *)ft_calloc((*tab)->p_total + 1, sizeof(pthread_t)); // creating one extra thread for monitoring
	bar_init(&(*tab)->start_blk, (*tab)->p_total + 2);
	return (0);
}
