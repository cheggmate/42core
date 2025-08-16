/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:20:47 by jotong            #+#    #+#             */
/*   Updated: 2025/08/16 23:58:27 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	will_die_during_action(t_phil *phil, char action)
{
	// printf("t_last_ate = %lld\n", phil->t_last_ate);
	// printf("get_time = %lld\n", get_time());
	// printf("time - t_last_ate = %lld\n", get_time() - phil->t_last_ate);
	// printf("t_slp + t_eat = %lld\n", phil->tb->t_slp + phil->tb->t_eat);
	if (action == 's')
	{
		if (get_time() - phil->t_last_ate < phil->tb->t_slp + phil->tb->t_eat)
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
