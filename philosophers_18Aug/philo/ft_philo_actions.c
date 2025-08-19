/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:27:11 by jotong            #+#    #+#             */
/*   Updated: 2025/08/19 09:27:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	let_philo_eat(t_phil *phil)
{
	if (phil->tb->stop == 0 && phil->state != 'd')
	{
		if (pick_up_frks(phil) == -1)
		{
			put_down_frks(phil);
			philo_died(phil);	// check if this is the right implementation
			// free_everything(phil->tb);
			return (-1);
		}
		else
		{
			phil->t_last_ate = get_time();
			phil->state = 'e';
			print_safely(phil);
			if (will_die_during_action(phil, 'e'))
			{
				sleep_safely(phil->t_last_ate + phil->tb->t_die);
				philo_died(phil);
			}
			else
			{
				sleep_safely(phil->tb->t_eat);
				// usleep(phil->tb->t_eat * 1000);
			}
			put_down_frks(phil);
			phil->n_eat -= 1;
			return (0);
		}
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
			sleep_safely(phil->tb->t_die - (get_time() - phil->t_last_ate));
			philo_died(phil);
		}
		else
		{
			sleep_safely(phil->tb->t_slp);		//only let him sleep the proper amount if he doesnt die
			// usleep(phil->tb->t_slp * 1000);
		}
		return (0);
	}
	else
		return (-1);
}

int	let_philo_think(t_phil *phil)
{
	long long	t_since_eat;

	t_since_eat = get_time() - phil->t_last_ate;
	if (phil->tb->stop == 0 && phil->state != 'd')
	{
		phil->state = 't';
		print_safely(phil);
		if (will_die_during_action(phil, 't'))
		{
			sleep_safely(phil->tb->t_die - (get_time() - phil->t_last_ate) - phil->tb->t_slp - phil->tb->t_eat);
			philo_died(phil);
		}
		if (t_since_eat > phil->tb->t_eat + phil->tb->t_slp + 20)
			sleep_safely(30);
		return (0);
	}
	else
		return (-1);
}

int	philo_died(t_phil *phil)
{
	printf("checking for death\n");
	if (phil->state == 'd')
		return (1);
	phil->state = 'd';
	print_safely(phil);
	put_down_frks(phil);
	return (0);
}
