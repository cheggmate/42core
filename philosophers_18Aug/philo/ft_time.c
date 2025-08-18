/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:20:47 by jotong            #+#    #+#             */
/*   Updated: 2025/08/19 00:29:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	will_die_during_action(t_phil *phil, char action)
{
	int	p_count;

	p_count = phil->tb->p_total;
	if (action == 's')
	{
		if (get_time() - phil->t_last_ate + phil->tb->t_slp  >  (1 + (p_count == 3 && phil->n == 2)) * phil->tb->t_die)
			return (1);
		else
			return (0);
	}
	return (0);
}

long long	get_time(void)
{
	struct timeval	now;
	long long		curr;

	curr = 0;
	gettimeofday(&now, NULL);
	curr = now.tv_sec * 1000LL;
	curr += now.tv_usec / 1000LL;
	return (curr);
}

void	sleep_safely(long long dur)
{
	long long		start;

	start = get_time();
	while(get_time() - start < dur)
		usleep(1000);
}
