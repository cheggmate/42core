/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:59:55 by jotong            #+#    #+#             */
/*   Updated: 2025/08/19 23:36:03 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	has_died_or_finished_eating(t_tab *tab)
{
	int	i;

	i = -1;
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
			return (-1);
		}
		if (tab->eat_count > 0 && tab->p_eat == tab->p_total)
		{
			// if (tab->phils[i].n_eat >= tab->eat_count)
			// 	p_meet_eat_count++;
			// printf("p_meet_eat_count = %d\n", p_meet_eat_count);
			// if (tab->eat_count > 0 && p_meet_eat_count == tab->p_total)
			// {
			// 	printf("everyone ate %d times \n", tab->eat_count);
			// 	tab->stop = 1;
			// 	return (1);
			// }
		
			printf("everyone ate %d times \n", tab->eat_count);
			tab->stop = 1;
			return (1);
		}
	}
	return (0);
}

void	*monitoring(void *t)
{
	t_tab *tab;
	
	tab = (t_tab *)t;
	bar_wait(&tab->start_blk);
	while(tab->stop == 0)
	{
		printf("eat count = %d\n", tab->eat_count);
		printf("p_eat = %d\n", tab->p_eat);
		if (has_died_or_finished_eating(tab))
		{
			printf("stop flag set\n");
			fflush(stdout);
			lock_stop_mutex(tab);
			tab->stop = 1;
			unlock_stop_mutex(tab);
			return (NULL);
		}
		else
			sleep_safely(1000);
	}
	return (NULL);
}
