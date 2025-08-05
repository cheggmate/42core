/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:09:01 by jotong            #+#    #+#             */
/*   Updated: 2025/08/06 00:17:58 by jotong           ###   ########.fr       */
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

// typedef struct s_pool
// {
// 	char	*head;
// 	size_t	total;
// 	size_t	used;	
// }	t_pool;

// typedef struct s_frk
// {
// 	size_t	f_num;
// 	size_t	f_state;
// }	t_frk;

typedef struct s_tab t_tab;

typedef struct s_phil
{
	pthread_t		*thread;
	unsigned char	state;
	long long		t_last_ate;
	t_tab			*tb;
	int				n;
	int				eat_count;
}	t_phil;

typedef struct s_tab
{
	// t_frk		*forks;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_phil			*phils;
	pthread_t		*threads;
	int				p_total;
	long long		t_eat;
	long long		t_slp;
	long long		t_die;
	int				eat_count;
	int				stop;
	pthread_mutex_t	s_lock;
}	t_tab;

// void	*alloc_mem(t_pool *mem_p, size_t size);
int			check_is_num(char *str);
int			check_num_limits(int num);
int			close_threads(t_tab *tab);
int			create_threads(t_tab **tab);
int			destroy_forks(t_tab *tab);
int			destroy_other_mutexes(t_tab *tab);
void 		free_everything(t_tab *tab);
// void		free_everything(t_pool *mem_p, t_tab **tab);
// void		free_pool(t_pool *mem_p);
void		*ft_memset(void *ptr, int value, size_t num);
long long	get_time(void);
void		*ft_calloc(size_t num, size_t size);
// int		ft_atoi(const char *str);
// t_pool	*init_mem_pool(size_t size);
int			init_tab(t_tab **tab);
int			check_is_num(char *str);
int			join_threads(t_tab *tab);
void		*keep_philos_alive(void *arg);
int			pick_up_frks(t_phil *phil);
int			put_down_frks(t_phil * phil);
void		print_safely(t_phil *phil);
int			philo_died(t_phil *phil);
int			let_philo_think(t_phil *phil);
int			let_philo_sleep(t_phil *phil);
int			let_philo_eat(t_phil *phil);
int			lock_stop_mutex(t_tab *tab);
int			unlock_stop_mutex(t_tab *tab);

#endif