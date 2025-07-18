/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:48 by jotong            #+#    #+#             */
/*   Updated: 2025/07/19 00:27:36 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define POOL_SIZE 1024 * 1024
# define CHUNK_SIZE 64;

typedef struct s_pool {
	char	*head;
	size_t	total;
	size_t	used;	
} t_pool;

typedef struct s_map {
	int		h;
	int		w;
	char	**grid;
} t_map;

# include <stdio.h>

t_pool		*init_mem_pool(size_t size);
void		*alloc_mem(t_pool *mem_p, size_t size);
void		free_pool(t_pool *mem_p);
int			get_map_height(char	*f_map);
t_map		*load_map(t_pool mem_pool, char *f_map);
void		free_end_exit(t_pool *mem_p, int status);

#endif