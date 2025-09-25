/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/09/25 23:40:33 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	pick_forks_odd(t_phil *phil, int fork_r, int n)
{
	if (pthread_mutex_lock(&phil->tb->forks[fork_r]) != 0)
		return (-1);
	phil->tb->f_owners[fork_r] = n;
	set_phil_state(phil, 'f');
	print_safely(phil);
	if (pthread_mutex_lock(&phil->tb->forks[n]) == 0)
	{
		phil->tb->f_owners[n] = n;
		print_safely(phil);
	}
	else
		put_down_frks(phil, 1);
	return (0);
}

static int	pick_forks_even(t_phil *phil, int fork_r, int n)
{
	if (pthread_mutex_lock(&phil->tb->forks[n]) == 0)
	{
		phil->tb->f_owners[n] = n;
		set_phil_state(phil, 'f');
		print_safely(phil);
		if (phil->tb->p_total != 1)
		{
			if (pthread_mutex_lock(&phil->tb->forks[fork_r]) == 0)
			{
				phil->tb->f_owners[fork_r] = n;
				print_safely(phil);
				return (0);
			}
			put_down_frks(phil, 1);
			return (-1);
		}
		sleep_safely(phil->tb->t_die);
		fprintf(stderr, "0 put down fork\n");
		put_down_frks(phil, 1);
		return (-1);
	}
	return (0);
}

static void	calc_fork_r(t_phil *phil, int *fork_r, int n)
{
	if (phil->tb->p_total % 2 == 1 && n == phil->tb->p_total - 1
		&& get_phil_eat(phil) == 0)
		sleep_safely(1);
	if (n != phil->tb->p_total - 1)
		*fork_r = n + 1;
	else
		*fork_r = 0;
}

int	pick_up_frks(t_phil *phil)
{
	int	n;
	int	fork_r;
	int	result;

	n = phil->n;
	result = 0;
	calc_fork_r(phil, &fork_r, n);
	if (check_phil_state(phil, 'd') == 1)
		return (-1);
	if (n % 2 == 1)
	{
		result = pick_forks_odd(phil, fork_r, n);
		if (result == -1)
			return (result);
	}
	else
	{
		result = pick_forks_even(phil, fork_r, n);
		if (result == -1)
		{
			put_down_frks(phil, 1);
			return (result);
		}
	}
	return (0);
}

int	put_down_frks(t_phil *phil, int f_picked)
{
	int	f_philo[2];
	// int	i;

	// i = -1;
	f_philo[0] = phil->n;
	calc_fork_r(phil, &f_philo[1], phil->n);
	fprintf(stderr, "f_picked = %d\n", f_picked);
	if (f_picked == 0)
		return (0);
	// if (phil->n != phil->tb->p_total - 1)
	// 	f_philo[1] = phil->n + 1;
	// else
	// 	f_philo[1] = 0;
	// while (++i < 2)
	// {
	// 	if (phil->tb->f_owners[f_philo[i]] == phil->n)
	// 	{
	// 		phil->tb->f_owners[f_philo[i]] = -1;
	// 		pthread_mutex_unlock(&phil->tb->forks[f_philo[i]]);
	// 	}
	// }
	if (f_picked == 2)
	{
		if (phil->n % 2 == 1)
		{
			phil->tb->f_owners[f_philo[0]] = -1;
			pthread_mutex_unlock(&phil->tb->forks[f_philo[0]]);
		}
		else
		{
			phil->tb->f_owners[f_philo[1]] = -1;
			pthread_mutex_unlock(&phil->tb->forks[f_philo[1]]);
		}
	}
	if (phil->n % 2 == 1)
	{
		phil->tb->f_owners[f_philo[1]] = -1;
		pthread_mutex_unlock(&phil->tb->forks[f_philo[1]]);
	}
	else
	{
		phil->tb->f_owners[f_philo[0]] = -1;
		pthread_mutex_unlock(&phil->tb->forks[f_philo[0]]);
	}
	return (0);
}
