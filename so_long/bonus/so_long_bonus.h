/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:48 by jotong            #+#    #+#             */
/*   Updated: 2025/07/25 23:07:01 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define POOL_SIZE 1048576
# define CHUNK_SIZE 64
# define VIEWPORT_HEIGHT 6
# define VIEWPORT_WIDTH 15
# define SPRITE_SIZE 128

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>

# ifdef __linux__
#  include <X11/keysym.h>
#  define KEY_W XK_w
#  define KEY_A XK_a
#  define KEY_S XK_s
#  define KEY_D XK_d
#  define KEY_ESC XK_Escape
# elif __APPLE__
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
# endif

typedef struct s_pool
{
	char	*head;
	size_t	total;
	size_t	used;	
}	t_pool;

typedef struct s_map
{
	int		h;
	int		w;
	int		c;
	int		start;
	int		exit;
	int		fd;
	int		p_start_x;
	int		p_start_y;
	char	**grid;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*p_img;
	void	*c_img;
	void	*w_img;
	void	*bg_img;
	void	*e_img;
	void	*e2_img;
	int		c_count;
	int		n_mvmts;
	int		v_x;
	int		v_y;
	int		view_w;
	int		view_h;
	int		p_x;
	int		p_y;
	char	*mp;
	t_map	*map;
	t_pool	*mem_p;
}	t_game;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_queue
{
	t_pos	q[10000];
	int		front;
	int		back;
	int		**dir;
}	t_queue;

void		get_map_edges(t_game **game, char *f_map);
void		calculate_viewable_area(t_game **game);
t_pool		*init_mem_pool(size_t size);
void		*alloc_mem(t_pool *mem_p, size_t size);
void		free_pool(t_pool *mem_p);
void		init_grid(t_pool *mem_p, char *f_map, t_game **game);
void		init_game(t_pool *mem_p, t_game **game, char *f_map);
void		initialise_map_values(t_game **game, char *f_map);
int			close_window(void *game);
void		destroy_images(t_game **game);
int			get_map_height(char	*f_map);
int			check_asset_exist(char *f_name);
void		check_asset_list(void);
void		check_asset_list2(void);
void		load_map(char *f_map, t_game **game);
void		reload_map(t_game **game, int prev_x, int prev_y);
void		show_images(t_game *game);
void		show_background(t_game *game);
void		show_collectible(t_game *game);
void		show_exit(t_game *game, int state);
void		show_player(t_game *game);
void		redraw_player(t_game *game);
void		show_walls(t_game *game);
void		print_map(t_map *map);
void		render_map(t_pool **mem_p, t_game **game);
void		render_viewable_map(t_game **game);
void		set_view_dimensions(t_game **game);
int			handle_keypress(int keycode, void *game);
void		check_update_element_ctr(t_pool *mem_p, t_game **game,
				char c, int *pos);
void		free_and_exit(t_pool *mem_p, t_game **game, int status, char *msg);
int			path_check(char **grid, t_game **game, t_pool *mem_p);

#endif