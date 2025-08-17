/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:20:47 by jotong            #+#    #+#             */
/*   Updated: 2025/08/17 12:11:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	will_die_during_action(t_phil *phil, char action)
{
	if (action == 's')
	{
		if (get_time() - phil->t_last_ate + phil->tb->t_slp  >  phil->tb->t_die)
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
		usleep(100);
}
