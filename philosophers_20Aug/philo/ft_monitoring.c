/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:59:55 by jotong            #+#    #+#             */
/*   Updated: 2025/08/25 00:04:38 by jotong           ###   ########.fr       */
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
			printf("phil state is already d\n");
			pthread_mutex_lock(&tab->s_lock);
			tab->stop = 1;
			pthread_mutex_unlock(&tab->s_lock);
			return (1);
		}
		else if (get_time() - tab->phils[i].t_last_ate > tab->t_die)
		{
			philo_died(&tab->phils[i]);
			return (1);
		}
		if (tab->eat_count > 0 && tab->phils[i].n_eat >= tab->eat_count)
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
	// printf("[T] about to bar_wait: tab=%p start_blk=%p trip=%d\n",
    //    tab, &tab->start_blk, tab->start_blk.count);
	bar_wait(&tab->start_blk);
	printf("monitoring thread passed start barrier\n");
	printf("stop flag = %d\n", check_stop_set(tab));
	while(check_stop_set(tab) == 0)
	{
		// printf("eat count = %d\n", tab->eat_count);
		// printf("p_eat = %d\n", tab->p_eat);
		stopped = has_died_or_finished_eating(tab);
		if (stopped)
		{
			printf("stop flag set\n");
			fflush(stdout);
			pthread_mutex_lock(&tab->s_lock);
			tab->stop = 1;
			pthread_mutex_unlock(&tab->s_lock);
			return (NULL);
		}
		else
			sleep_safely(10);
	}
	return (NULL);
}
