/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_loader_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:35:45 by jotong            #+#    #+#             */
/*   Updated: 2025/07/22 00:02:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

void	show_background(t_map *map, t_game *game)
{
	void	*bg;
	int		bg_edge;
	int		i;
	int		j;

	i = -1;
	bg_edge = 32;
	bg = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &bg_edge, &bg_edge);
	printf("create bg sprite\n");
	while (i++ < map->h - 1)
	{
		j = -1;
		while (j++ < map->w -1)
			mlx_put_image_to_window(game->mlx, game->window, bg, i * SPRITE_SIZE, j * SPRITE_SIZE);
	}
	printf("Created background\n");
}

void	show_walls(t_map *map, t_game *game)
{
	void	*wall;
	int		wall_edge;
	int		i;
	int		j;

	i = -1;
	wall_edge = 32;
	wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &wall_edge, &wall_edge);
	printf("create wall sprite\n");
	while (i++ < map->h - 1)
	{
		j = -1;
		while (j++ < map->w - 1)
		{
			if (map->grid[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, wall, i * SPRITE_SIZE, j * SPRITE_SIZE);
		}
	}
	printf("Created walls\n");
}

void	show_exit(t_map *map, t_game *game, int state)
{
	void	*exit;
	int		exit_edge;
	int		i;
	int		j;

	i = -1;
	exit_edge = 32;
	if (state == 1)
		exit = mlx_xpm_file_to_image(game->mlx, "assets/door.xpm", &exit_edge, &exit_edge);
	else
		exit = mlx_xpm_file_to_image(game->mlx, "assets/door-open.xpm", &exit_edge, &exit_edge);
	printf("create exit sprite\n");
	while (i++ < map->h - 1)
	{
		j = -1;
		while (j++ < map->w - 1)
		{
			if (map->grid[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, exit, i * SPRITE_SIZE, j * SPRITE_SIZE);
		}
	}
	printf("Created exit\n");
}

void	show_collectible(t_map *map, t_game *game)
{
	void	*c;
	int		c_edge;
	int		i;
	int		j;

	i = -1;
	c_edge = 32;
	c = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &c_edge, &c_edge);
	printf("create collectible sprite\n");
	while (i++ < map->h - 1)
	{
		j = -1;
		while (j++ < map->w - 1)
		{
			if (map->grid[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, c, i * SPRITE_SIZE, j * SPRITE_SIZE);
		}
	}
	printf("Created collectible\n");
}
