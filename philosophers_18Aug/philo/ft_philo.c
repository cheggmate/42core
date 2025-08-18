/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:35:46 by jotong            #+#    #+#             */
/*   Updated: 2025/08/19 00:17:00 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// alt philos pick up left OR right fork
// each philo must get allocated fork before trying to reach for the other.

// philos will do:
// Eat
// Sleep
// Think

// The simulation stops when a philosopher dies of starvation.

// inputs: 
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
//
// breakdown:
// time_to_die (in milliseconds): If a philosopher has not started eating within time_to_die milliseconds since the start of their last meal or the start of the
// simulation, they die.
// time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
// time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
// number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat 
// times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

// Logs:
// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died
// X = philosopher number
// timestamp_in_ms = current timestamp in milliseconds

// Each philo must be represented in its own thread
// Each fork must have its own state.


// pseudocode:
// check if there is at least 5 args (including the program name), and at most 6. otherwise return an error.
// set the input into its own variables
// initialise variables needed for philosophers
// set up the struct/array (?) needed for the philos in the table.
// -store current state (eating / sleeping / thinking / dead)
// -time spent in the state
// -store allowed time left till next state

// validations:
// - must check the number of inputs
// - time_to_die must be more than time_to_sleep
// - num of philos need to be less than size_max


// End clause:
// If the number of times EACH philosopher has eaten is reached
// If ANY philosopher dies

// Allowed functions:
// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

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

void	*keep_philos_alive(void *arg)
{
	t_phil *phil;
	int		result;

	phil = (t_phil *)arg;
    bar_wait(&phil->tb->start_blk);
	bar_wait(&phil->tb->start_blk);
	while (phil->tb->stop == 0 && phil->state != 'd' && (phil->n_eat == 0 || phil->n_eat < phil->tb->eat_count))
	{
		result = let_philo_eat(phil);
		if (result == -1)
			break ;
		result = let_philo_sleep(phil);
		// printf("phil finished sleeping\n");
		if (result == -1)
			break ;
		result = let_philo_think(phil);
		if (result == -1)
			break ;
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
	result = var_checks(argc, argv);
	if (result == -1)
		return (write(2, "Error\nInvalid inputs.\n", 22), 1);
	if (init_tab(&tab, argc, argv) != 0)
		return (write(2, "Could not allocate memory!\n", 27), 1);
	pthread_mutex_init(&tab->s_lock, NULL);
	lock_stop_mutex(tab);
	create_threads(tab);
	bar_wait(&tab->start_blk);
	tab->t_start = get_time();
	bar_wait(&tab->start_blk);
	join_threads(tab);
	if (result == -1)
		return (1);
	return (0);
}
