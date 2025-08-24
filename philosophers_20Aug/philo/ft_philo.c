/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:35:46 by jotong            #+#    #+#             */
/*   Updated: 2025/08/24 22:52:09 by jotong           ###   ########.fr       */
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
	printf("Philo %d reached start barrier\n", phil->n);
	printf("[T] about to bar_wait: tab=%p start_blk=%p trip=%d\n",
       phil->tb, &phil->tb->start_blk, phil->tb->start_blk.count);
    bar_wait(&phil->tb->start_blk);
	printf("Philo %d passed start barrier\n", phil->n);
	// bar_wait(&phil->tb->start_blk);
	fflush(stdout);
	// usleep(100);
	// pthread_mutex_lock(&phil->lock);
	// pthread_mutex_lock(&phil->tb->s_lock);
	while (check_stop_set(phil->tb) == 0 && check_phil_state(phil, 'd') == 1 && (phil->n_eat == 0 || phil->n_eat < phil->tb->eat_count))
	{
		result = let_philo_eat(phil);
		if (result == -1 || check_stop_set(phil->tb) == 1|| check_phil_state(phil, 'd') == 1)
		{
			// pthread_mutex_unlock(&phil->lock);
			// pthread_mutex_unlock(&phil->tb->s_lock);
			break ;
		}
		result = let_philo_sleep(phil);
		// printf("phil finished sleeping\n");
		pthread_mutex_lock(&phil->lock);
		if (result == -1 || check_stop_set(phil->tb) == 1 || check_phil_state(phil, 'd') == 1)
		{
			pthread_mutex_unlock(&phil->lock);
			pthread_mutex_unlock(&phil->tb->s_lock);
			break ;
		}
		result = let_philo_think(phil);
		pthread_mutex_lock(&phil->lock);
		pthread_mutex_lock(&phil->tb->s_lock);
		if (result == -1 || check_stop_set(phil->tb) == 1 || check_phil_state(phil, 'd') == 1)
		{
			pthread_mutex_unlock(&phil->lock);
			pthread_mutex_unlock(&phil->tb->s_lock);
			break ;
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_tab	*tab;
	int		result;

	tab = NULL;
	printf("test1\n");
	setvbuf(stdout, NULL, _IONBF, 0);
	if (argc < 5 || argc > 6)
		return (write(2, "Invalid no. of args!\n", 21), 1);
	result = var_checks(argc, argv);
	if (result == -1)
		return (write(2, "Error\nInvalid inputs.\n", 22), 1);
	printf("before init tab\n");
	if (init_tab(&tab, argc, argv) != 0)
		return (write(2, "Could not allocate memory!\n", 27), 1);
	printf("before init thread \n");
	pthread_mutex_init(&tab->s_lock, NULL);
	printf("inited pthreads\n");
	
	result = create_threads(tab);
	printf("done creating threads with result %d\n", result);
	if (result != 0)
	{
		printf("failed to create all threads, returning\n");
		free_tab_everything(tab);
		return (1);
	}
	printf("done creating threads\n");
	printf("[T] about to bar_wait: tab=%p start_blk=%p trip=%d\n",
       tab, &tab->start_blk, tab->start_blk.count);
	bar_wait(&tab->start_blk);
	printf("main thread passed waiting barrier\n");
	tab->t_start = get_time();
	printf("set start time\n");
	// bar_wait(&tab->start_blk);
	result = join_threads(tab);
	printf("stop flag is %d\n", tab->stop);
	
	free_tab_everything(tab);
	if (result == -1)
		return (1);
	return (0);
}
