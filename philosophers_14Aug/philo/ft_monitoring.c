/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:59:55 by jotong            #+#    #+#             */
/*   Updated: 2025/08/17 12:45:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	has_died_or_finished_eating(t_tab *tab)
{
	int	i;
	int	p_meet_eat_count;

	i = -1;
	p_meet_eat_count = 0;
	while (++i < tab->p_total)
	{
		if (tab->phils[i].state == 'd')
			return (1);
		else if (get_time() - tab->phils[i].t_last_ate > tab->t_die)
		{
			philo_died(&tab->phils[i]);
			return (1);
		}
		if (tab->eat_count > 0)
		{
			if (tab->phils[i].n_eat > tab->eat_count)
				p_meet_eat_count += 1;
		}
	}
	if (tab->eat_count > 0 && p_meet_eat_count == tab->p_total)
		return (1);
	return (0);
}

void	*monitoring(void *t)
{
	t_tab *tab;
	
	tab = (t_tab *)t;
	if (has_died_or_finished_eating(tab))
	{
		printf("stop flag set\n");
		lock_stop_mutex(tab);
		tab->stop = 1;
		unlock_stop_mutex(tab);
	}
	else
		sleep_safely(800);
		// usleep(800 * 1000);
	return NULL;
}
