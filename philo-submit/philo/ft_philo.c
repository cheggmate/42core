/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:35:46 by jotong            #+#    #+#             */
/*   Updated: 2025/09/24 10:49:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	var_checks(int argc, char **argv)
{
	int	num;

	num = check_is_num(argv[1]);
	if (num == -1 || check_num_limits(num) == -1 || num == 0)
		return (-1);
	num = check_is_num(argv[2]);
	if (num == -1 || check_num_limits(num) == -1)
		return (-1);
	num = check_is_num(argv[3]);
	if (num == -1 || check_num_limits(num) == -1)
		return (-1);
	num = check_is_num(argv[4]);
	if (num == -1 || check_num_limits(num) == -1)
		return (-1);
	if (argc == 6)
	{
		num = check_is_num(argv[5]);
		if (num == -1 || check_num_limits(num) == -1)
			return (-1);
	}
	return (0);
}

int	copy_values_into_vars(int argc, char **argv, t_tab **tab)
{
	int	num;

	num = check_is_num(argv[1]);
	(*tab)->p_total = num;
	num = check_is_num(argv[2]);
	(*tab)->t_die = num;
	num = check_is_num(argv[3]);
	(*tab)->t_eat = num;
	num = check_is_num(argv[4]);
	(*tab)->t_slp = num;
	if (argc == 6)
	{
		num = check_is_num(argv[5]);
		(*tab)->eat_count = num;
	}
	(*tab)->stop = 0;
	return (0);
}

static int	orchestrate_phil(t_phil *phil)
{
	if (let_philo_eat(phil) == -1)
	{
		philo_died(phil);
		return (-1);
	}
	if (!(get_phil_eat(phil) == 0
			|| get_phil_eat(phil) < phil->tb->eat_count
			|| phil->tb->eat_count == 0))
	{
		if (get_phil_eat(phil) == phil->tb->eat_count)
			return (-1);
		philo_died(phil);
		return (-1);
	}
	if (let_philo_sleep(phil) == -1)
	{
		philo_died(phil);
		return (-1);
	}
	if (let_philo_think(phil) == -1)
	{
		philo_died(phil);
		return (-1);
	}
	return (0);
}

void	*keep_philos_alive(void *arg)
{
	t_phil	*phil;

	phil = (t_phil *)arg;
	pthread_mutex_lock(&phil->tb->start);
	pthread_mutex_unlock(&phil->tb->start);
	while (check_stop_set(phil->tb) == 0 && check_phil_state(phil, 'd') == 0)
	{
		if (orchestrate_phil(phil) == -1)
			break ;
	}
	if (check_stop_set(phil->tb) == 1 && check_phil_state(phil, 'd') == 0)
	{
		philo_died(phil);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_tab	*tab;
	int		result;

	tab = NULL;
	if (argc < 5 || argc > 6)
		return (write(2, "Invalid no. of args!\n", 21), 1);
	if (var_checks(argc, argv) == -1)
		return (write(2, "Error\nInvalid inputs.\n", 22), 1);
	if (init_tab(&tab, argc, argv) != 0)
		return (write(2, "Could not allocate memory!\n", 27), 1);
	pthread_mutex_init(&tab->s_lock, NULL);
	pthread_mutex_lock(&tab->start);
	result = create_threads(tab);
	pthread_mutex_unlock(&tab->start);
	if (result != 0)
	{
		free_tab_everything(tab);
		return (1);
	}
	set_start_time(tab);
	result = join_threads(tab);
	free_tab_everything(tab);
	if (result == -1)
		return (1);
	return (0);
}
