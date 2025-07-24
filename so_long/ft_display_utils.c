/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:42:19 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 22:28:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
// #include "minilibx_opengl_20191021/mlx.h"
#include "minilibx-linux/mlx.h"

int	close_window(void *game)
{
	t_game	*game_tmp;

	game_tmp  = (t_game *)game;
	printf("before destroying window\n");
	if (game_tmp && game_tmp->mlx && game_tmp->window)
	{
		mlx_destroy_window(game_tmp->mlx, game_tmp->window);
		printf("freeing memory after destroying window\n");
		game_tmp->window = NULL;
	}
	free_and_exit(game_tmp->mem_p, &game_tmp, 0, "Window closed.");
	return (0);
}

static void	*create_window(t_pool *mem_p, t_game **game, void *mlx)
{
	int		width;
	int		height;

	width = ((*game)->map->w) * SPRITE_SIZE;
	height = (*game)->map->h * SPRITE_SIZE;
	(*game)->window = mlx_new_window(mlx, width, height, "so_long");
	if (!(*game)->window)
		free_and_exit(mem_p, game, 1, "Failed to open new window.\n");
	return ((*game)->window);
}

static void	show_images(t_map *map, t_game *game)
{
	show_background(map, game);
	show_walls(map, game);
	show_exit(map, game, 1);
	show_collectible(map, game);
	show_player(game);
	mlx_key_hook(game->window, handle_keypress, game);
}

void	check_asset_list2(void)
{
	if (check_asset_exist("assets/player_door_c.xpm") == -1)
	{
		write(2, "Error\nPlayer sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/player_door_o.xpm") == -1)
	{
		write(2, "Error\nPlayer sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/enemy.xpm") == -1)
	{
		write(2, "Error\nEnemy sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
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
	(*game)->window = create_window( *mem_p, game, (*game)->mlx);
	printf("before show images\n");
	show_images(map, (*game));
}
