/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:35:46 by jotong            #+#    #+#             */
/*   Updated: 2025/07/28 00:44:58 by jotong           ###   ########.fr       */
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
//  If a philosopher has not started eating within time_to_die milliseconds since the start of their last meal or the start of the
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

static int	copy_values_into_vars(int argc, char **argv, t_tab **tab)
{
	int	num;
	num = is_num(argv[1]);
	if (num == -1 || check_num_limits(num) == -1)
		return (-1);
	(*tab)->p_total = num;
	// continue with other values in the argv, insert into the respective var of the struct
}

int	main(int argc, char **argv)
{
	t_tab	*tab;
	int		result;

	if (argc < 5 || argc > 6)
		return (write(2, "Invalid no. of args!\n", 21), 1);
	if (!init_tab(&tab))
		return (write(2, "Could not allocate memory!\n", 27), 1);
	result = copy_values_into_vars(argc, argv, &tab);
	if (result == -1)
		return (1);
	create_threads(); // also need a master function that kicks off operations for one thread.
}
