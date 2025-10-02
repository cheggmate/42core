/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:09:01 by jotong            #+#    #+#             */
/*   Updated: 2025/10/01 21:41:26 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define POOL_SIZE 1048576
# define CHUNK_SIZE 64

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_tab	t_tab;

typedef struct s_phil
{
	pthread_mutex_t	*lock;
	unsigned char	state;
	long long		t_last_ate;
	t_tab			*tb;
	int				n;
	int				n_eat;
}	t_phil;

typedef struct s_tab
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	start;
	int				*f_owners;
	pthread_mutex_t	print;
	t_phil			*phils;
	pthread_t		*threads;
	int				fork_inited;
	int				p_total;
	long long		t_start;
	long long		t_eat;
	long long		t_slp;
	long long		t_die;
	int				p_eat;
	int				eat_count;
	int				stop;
	// int				philos_left;
	pthread_mutex_t	s_lock;
}	t_tab;

int			check_is_num(char *str);
int			check_num_limits(int num);
int			check_phil_state(t_phil *phil, unsigned char s);
int			check_stop_set(t_tab *tab);
int			close_threads(t_tab *tab);
int			copy_values_into_vars(int argc, char **argv, t_tab **tab);
int			create_threads(t_tab *tab);
int			destroy_forks(t_tab *tab);
int			destroy_other_mutexes(t_tab *tab);
void		free_tab_everything(t_tab *tab);
void		free_phil_everything(t_phil *phil);
void		*ft_memset(void *ptr, int value, size_t num);
int			get_phil_eat(t_phil *phil);
long long	get_time(void);
void		*ft_calloc(size_t num, size_t size);
int			init_tab(t_tab **tab, int argc, char **argv);
int			check_is_num(char *str);
long long	get_time_since_ate(t_phil *phil);
int			join_threads(t_tab *tab);
void		*keep_philos_alive(void *arg);
int			let_philo_think(t_phil *phil);
int			let_philo_sleep(t_phil *phil);
int			let_philo_eat(t_phil *phil);
void		*monitoring(void *t);
int			pick_up_frks(t_phil *phil);
int			put_down_frks(t_phil *phil);
void		print_safely(t_phil *phil);
int			philo_died(t_phil *phil);
int			set_phil_eat(t_phil *phil, long long new_time);
int			set_phil_state(t_phil *phil, char new_state);
void		set_start_time(t_tab *tab);
int			set_stop_flag(t_tab *tab);
void		sleep_safely(long long dur);
int			will_die_during_action(t_phil *phil, char action);

#endif