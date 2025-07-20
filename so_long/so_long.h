/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:48 by jotong            #+#    #+#             */
/*   Updated: 2025/07/20 14:49:55 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define POOL_SIZE 1024 * 1024
# define CHUNK_SIZE 64;

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_pool {
	char	*head;
	size_t	total;
	size_t	used;	
} t_pool;

typedef struct s_map {
	int		h;
	int		w;
	int		c;
	int		start;
	int		exit;
	int		fd;
	char	**grid;
} t_map;

int			get_map_height(char	*f_map);
t_pool		*init_mem_pool(size_t size);
void		*alloc_mem(t_pool *mem_p, size_t size);
void		free_pool(t_pool *mem_p);
t_map		*init_grid(t_pool *mem_p, int width, char *f_map, int fd);
int			get_map_height(char	*f_map);
t_map		*load_map(char *f_map);
void 		check_update_element_ctr(t_pool *mem_p, t_map *map, char c);
void		free_and_exit(t_pool *mem_p, int *fd, int status);

#endif