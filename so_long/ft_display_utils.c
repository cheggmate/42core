/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:42:19 by jotong            #+#    #+#             */
/*   Updated: 2025/07/22 00:59:03 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

static int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

static void	*create_window(t_pool *mem_p, t_map *map, void *mlx)
{
	void	*window;
	int		width;
	int		height;

	width = map->w * SPRITE_SIZE;
	height = map->h * SPRITE_SIZE;
	printf("before mlx new window\n");
	window = mlx_new_window(mlx, width, height, "so_long");
	if (!window)
		free_and_exit(mem_p, &map->fd, 1, "Failed to open new window.\n");
	return (window);
}

static void	show_images(t_map *map, t_game *game)
{
	show_background(map, game);
	show_walls(map, game);
	show_exit(map, game, 1);
	show_collectible(map, game);
	show_player(game, map->p_start_x, map->p_start_y);
	mlx_key_hook(game->window, handle_keypress, game);
	printf("bbbb\n");
	mlx_hook(game->window, 17, 0, close_window, game); // 17 = destroy Notify activity
}

void	check_asset_list(void)
{
	if (check_asset_exist("assets/player.xpm") == -1)
	{
		write(2, "Error\nPlayer sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/wall.xpm") == -1)
	{
		write(2, "Error\nWall sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/door.xpm") == -1)
	{
		write(2, "Error\nExit sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/collectible.xpm") == -1)
	{
		write(2, "Error\nCollectible sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/floor.xpm") == -1)
	{
		write(2, "Error\nFloor sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
}

void	render_map(t_pool **mem_p, t_map *map, t_game **game)
{
	*game = alloc_mem(*mem_p, sizeof(t_game));
	printf("allocating game memory\n");
	if (!(*game))
		free_and_exit(*mem_p, &map->fd, 1, "Failed to alloc mem for game.\n");
	(*game)->mlx = mlx_init();
	(*game)->p_x = map->p_start_x;
	(*game)->p_y = map->p_start_y;
	if (!(*game)->mlx)
		free_and_exit(*mem_p, &map->fd, 1, "Failed to init mlx.\n");
	(*game)->window = create_window( *mem_p, map, (*game)->mlx);
	printf("before show images\n");
	show_images(map, (*game));
}
