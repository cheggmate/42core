/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:59:55 by jotong            #+#    #+#             */
/*   Updated: 2025/08/18 00:18:45 by jotong           ###   ########.fr       */
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
		{
			printf("phil state is already d\n");
			return (1);
		}
		else if (get_time() - tab->phils[i].t_last_ate > tab->t_die)
		{
			printf("killed philo\n");
			philo_died(&tab->phils[i]);
			return (1);
		}
		if (tab->eat_count > 0)
		{
			// printf("eat count check\n");
			// printf("1n_eat = %d\n", tab->phils[i].n_eat);
			if (tab->phils[i].n_eat > tab->eat_count)
				p_meet_eat_count += 1;
		}
	}
	if (tab->eat_count > 0 && p_meet_eat_count == tab->p_total)
	{
		printf("eat count alr met\n");
		return (1);
	}
	return (0);
}

void	*monitoring(void *t)
{
	t_tab *tab;
	
	tab = (t_tab *)t;
	bar_wait(&tab->start_blk);
	bar_wait(&tab->start_blk);
	if (has_died_or_finished_eating(tab))
	{
		printf("stop flag set\n");
		fflush(stdout);
		lock_stop_mutex(tab);
		tab->stop = 1;
		unlock_stop_mutex(tab);
	}
	else
		sleep_safely(800);
		// usleep(800 * 1000);
	return NULL;
}
