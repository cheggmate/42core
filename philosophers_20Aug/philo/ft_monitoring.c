/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:59:55 by jotong            #+#    #+#             */
/*   Updated: 2025/08/28 22:51:24 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	has_died_or_finished_eating(t_tab *tab)
{
	int	i;
	int	p_finished_eating;

	i = -1;
	p_finished_eating = 0;
	while (++i < tab->p_total)
	{
		if (check_phil_state(&tab->phils[i], 'd') == 1)
		{
			set_stop_flag(tab);
			return (1);
		}
		else if (get_time_since_ate(&(tab->phils[i])) >= tab->t_die)
		{
			philo_died(&tab->phils[i]);
			return (1);
		}
		if (tab->eat_count > 0 && get_phil_eat(&(tab->phils[i])) >= tab->eat_count)
			p_finished_eating++;
	}
	if (p_finished_eating == tab->p_total)
		return (1);
	return (0);
}

void	*monitoring(void *t)
{
	t_tab *tab;
	int	stopped;
	
	tab = (t_tab *)t;
	bar_wait(&tab->start_blk);
	while(check_stop_set(tab) == 0)
	{
		stopped = has_died_or_finished_eating(tab);
		if (stopped)
		{
			// printf("stop flag set\n");
			fflush(stdout);
			set_stop_flag(tab);
			return (NULL);
		}
		else
			sleep_safely(10);
	}
	return (NULL);
}
