/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:59:55 by jotong            #+#    #+#             */
/*   Updated: 2025/09/14 23:58:08 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	kill_everybody(t_tab *tab)
{
	int	i;

	i = -1;
	while (i++ < tab->p_total)
	{
		set_phil_state(&tab->phils[i], 'd');
	}
	return (0);
}

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
			kill_everybody(tab);
			return (1);
		}
		else if (get_time_since_ate(&(tab->phils[i])) >= tab->t_die)
		{
			philo_died(&tab->phils[i]);
			kill_everybody(tab);
			return (1);
		}
		if (tab->eat_count > 0
			&& get_phil_eat(&(tab->phils[i])) >= tab->eat_count)
			p_finished_eating++;
	}
	if (p_finished_eating == tab->p_total)
		return (1);
	return (0);
}

static int	phils_have_not_died(t_tab *tab)
{
	int	i;

	i = -1;
	while (++i < tab->p_total)
	{
		if (check_phil_state(&tab->phils[i], 'd') == 0)
			return (0);
	}
	return (1);
}

void	*monitoring(void *t)
{
	t_tab	*tab;
	int		stopped;

	tab = (t_tab *)t;
	pthread_mutex_lock(&tab->start);
	pthread_mutex_unlock(&tab->start);
	while (check_stop_set(tab) == 0)
	{
		stopped = has_died_or_finished_eating(tab);
		if (stopped)
		{
			set_stop_flag(tab);
			return (NULL);
		}
		else
			sleep_safely(10);
	}
	while (phils_have_not_died(tab) == 0)
		sleep_safely(100);
	return (NULL);
}
