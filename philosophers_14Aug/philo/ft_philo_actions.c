/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:27:11 by jotong            #+#    #+#             */
/*   Updated: 2025/08/14 13:18:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	let_philo_eat(t_phil *phil)
{
	if (phil->tb->stop == 0)
	{
		pick_up_frks(phil);
		phil->state = 'e';
		print_safely(phil);
		usleep(phil->tb->t_eat);
		put_down_frks(phil);
		phil->t_last_ate = get_time();
		phil->eat_count += 1;
		return (0);
	}
	else
		return (-1);
}

int	let_philo_sleep(t_phil *phil)
{
	if (phil->tb->stop == 0)
	{
		phil->state = 's';
		print_safely(phil);
		usleep(phil->tb->t_slp);
		return (0);
	}
	else
		return (-1);
}

int	let_philo_think(t_phil *phil)
{
	if (phil->tb->stop == 0)
	{
		phil->state = 't';
		print_safely(phil);
		return (0);
	}
	else
		return (-1);
}

int	philo_died(t_phil *phil)
{
	phil->state = 'd';
	print_safely(phil);
	return (0);
}
