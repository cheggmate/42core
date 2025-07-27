/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:09:01 by jotong            #+#    #+#             */
/*   Updated: 2025/07/28 00:41:51 by jotong           ###   ########.fr       */
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

typedef struct s_pool
{
	char	*head;
	size_t	total;
	size_t	used;	
}	t_pool;

typedef struct s_frk
{
	size_t	*f_num;
	size_t	*f_state;
}	t_frk;

typedef struct s_phil
{
	pthread_t	*thread;
	size_t		*state;
	size_t		*action;
	size_t		*t_since_eat;
}	t_phil;

typedef struct s_tab
{
	t_frk	*forks;
	t_phil	*phils;
	size_t	p_total;
	size_t	t_eat;
	size_t	t_slp;
	size_t	t_die;
	size_t	eat_count;
}	t_tab;

void	*alloc_mem(t_pool *mem_p, size_t size);
int		check_is_num(char *str);
int		check_num_limits(size_t num);
void	free_everything(t_pool *mem_p, t_tab **tab);
void	free_pool(t_pool *mem_p);
void	*ft_calloc(size_t num, size_t size);
// int		ft_atoi(const char *str);
t_pool	*init_mem_pool(size_t size);
int		init_tab(t_tab **tab, t_pool *mem_p);

#endif PHILO_H