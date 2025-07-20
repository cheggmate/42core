/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:48 by jotong            #+#    #+#             */
/*   Updated: 2025/07/21 00:24:09 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define POOL_SIZE 1024 * 1024
# define CHUNK_SIZE 64
# define SPRITE_SIZE 32

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

#ifdef __linux__
# include <X11/keysym.h>
# define KEY_W XK_w
# define KEY_A XK_A
# define KEY_S XK_S
# define KEY_D XK_D
# define KEY_ESC XK_Escape
#elif __APPLE__
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
#endif

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
	int		p_start_x;
	int		p_start_y;
	char	**grid;
} t_map;

typedef struct s_game {
	void	*mlx;
	void	*window;
	int		p_x;
	int		p_y;
	t_map	*map;
} t_game;

int			get_map_height(char	*f_map);
t_pool		*init_mem_pool(size_t size);
void		*alloc_mem(t_pool *mem_p, size_t size);
void		free_pool(t_pool *mem_p);
t_map		*init_grid(t_pool *mem_p, int width, char *f_map, int fd);
int			get_map_height(char	*f_map);
t_map		*load_map(char *f_map, t_game *game);
void		print_map(t_map *map);
void		render_map(t_pool *mem_p, t_map *map, t_game *game);
int			handle_keypress(int keycode, t_game *game);
void 		check_update_element_ctr(t_pool *mem_p, t_map *map, char c, int *pos);
void		free_and_exit(t_pool *mem_p, int *fd, int status);

#endif