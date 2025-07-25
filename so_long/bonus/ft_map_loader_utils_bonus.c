/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_loader_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:35:45 by jotong            #+#    #+#             */
/*   Updated: 2025/07/25 23:08:52 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

void	show_background(t_game *game)
{
	void	*bg;
	int		bg_edge;

	bg_edge = 32;
	bg = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&bg_edge, &bg_edge);
	game->bg_img = bg;
}

void	show_walls(t_game *game)
{
	void	*wall;
	int		wall_edge;

	wall_edge = 32;
	wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&wall_edge, &wall_edge);
	game->w_img = wall;
}

void	show_exit(t_game *game, int state)
{
	void	*exit;
	int		exit_edge;

	exit_edge = 32;
	if (state == 1)
		exit = mlx_xpm_file_to_image(game->mlx, "assets/door.xpm",
				&exit_edge, &exit_edge);
	else
		exit = mlx_xpm_file_to_image(game->mlx, "assets/door_open.xpm",
				&exit_edge, &exit_edge);
	game->e2_img = mlx_xpm_file_to_image(game->mlx, "assets/player_door_c.xpm",
			&exit_edge, &exit_edge);
	game->e_img = exit;
}

void	show_collectible(t_game *game)
{
	void	*c;
	int		c_edge;

	c_edge = 32;
	c = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm",
			&c_edge, &c_edge);
	game->c_img = c;
}
