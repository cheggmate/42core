/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:27:11 by jotong            #+#    #+#             */
/*   Updated: 2025/08/17 12:42:59 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	let_philo_eat(t_phil *phil)
{
	if (phil->tb->stop == 0 && phil->state != 'd')
	{
		pick_up_frks(phil);
		phil->t_last_ate = get_time();
		phil->state = 'e';
		print_safely(phil);
		sleep_safely(phil->tb->t_eat);
		// usleep(phil->tb->t_eat * 1000);
		put_down_frks(phil);
		phil->n_eat -= 1;
		return (0);
	}
	else
		return (-1);
}

int	let_philo_sleep(t_phil *phil)
{
	if (phil->tb->stop == 0 && phil->state != 'd')
	{
		phil->state = 's';
		print_safely(phil);
		if (will_die_during_action(phil, 's'))
		{
			printf("philo %d will die during sleep\n", phil->n);
			sleep_safely(phil->t_last_ate + phil->tb->t_die);
			// usleep((phil->t_last_ate + phil->tb->t_die) * 1000);
			philo_died(phil);
		}
		else
		{
			// printf("philo will sleep for %lld seconds\n", phil->tb->t_slp);
			sleep_safely(phil->tb->t_slp);
			// usleep(phil->tb->t_slp * 1000);
		}
		return (0);
	}
	else
		return (-1);
}

int	let_philo_think(t_phil *phil)
{
	if (phil->tb->stop == 0 && phil->state != 'd')
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
