/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:27:11 by jotong            #+#    #+#             */
/*   Updated: 2025/09/25 23:58:11 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	let_philo_eat(t_phil *phil)
{
	if (check_stop_set(phil->tb) == 0 && check_phil_state(phil, 'd') == 0)
	{
		if (pick_up_frks(phil) == -1)
		{
			// put_down_frks(phil);
			philo_died(phil);
			return (-1);
		}
		set_phil_eat(phil, get_time());
		print_safely(phil);
		if (will_die_during_action(phil, 'e'))
		{
			sleep_safely(phil->tb->t_die);
			put_down_frks(phil, 2);
			philo_died(phil);
			return (-1);
		}
		sleep_safely(phil->tb->t_eat);
		put_down_frks(phil, 2);
		return (0);
	}
	else if (check_stop_set(phil->tb) == 0)
		set_phil_state(phil, 'd');
	return (-1);
}

int	let_philo_sleep(t_phil *phil)
{
	if (check_stop_set(phil->tb) == 0 && check_phil_state(phil, 'd') == 0)
	{
		set_phil_state(phil, 's');
		print_safely(phil);
		if (will_die_during_action(phil, 's'))
		{
			sleep_safely(phil->tb->t_die - get_time_since_ate(phil));
			philo_died(phil);
			return (-1);
		}
		else
		{
			sleep_safely(phil->tb->t_slp);
			return (1);
		}
	}
	else if (check_stop_set(phil->tb) == 0)
		set_phil_state(phil, 'd');
	return (-1);
}

int	let_philo_think(t_phil *phil)
{
	if (check_stop_set(phil->tb) == 0 && check_phil_state(phil, 'd') == 0)
	{
		set_phil_state(phil, 't');
		print_safely(phil);
		if (will_die_during_action(phil, 't'))
		{
			sleep_safely(phil->tb->t_die - get_time_since_ate(phil));
			philo_died(phil);
			return (-1);
		}
		else
		{
			sleep_safely(1);
			return (1);
		}
	}
	else if (check_stop_set(phil->tb) == 0)
		set_phil_state(phil, 'd');
	return (-1);
}

int	philo_died(t_phil *phil)
{
	if (check_phil_state(phil, 'd') == 1)
		return (-1);
	set_phil_state(phil, 'd');
	print_safely(phil);
	set_stop_flag(phil->tb);
	return (0);
}
