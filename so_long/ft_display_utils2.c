/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:57:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 22:31:56 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
// #include "minilibx_opengl_20191021/mlx.h"
#include "minilibx-linux/mlx.h"

void	reload_map(t_game **game, int prev_x, int prev_y)
{
	printf("trying to reload the map\n");
	if ((*game)->map->grid[prev_x][prev_y] == 'C')
	{
		(*game)->c_count += 1;
		(*game)->map->grid[prev_x][prev_y] = '0';
		printf("incremented c_count\n");
	}
	if ((*game)->map->grid[prev_x][prev_y] == 'P')
		(*game)->map->grid[prev_x][prev_y] = '0';
	printf("redrawing the tile at [%d][%d]\n", prev_y, prev_x);
	redraw_tile(*game, prev_x, prev_y);
	printf("redrawing the player at [%d][%d]\n", (*game)->p_y, (*game)->p_x);
	redraw_player(*game);
}

void	redraw_tile(t_game *game, int pos_x, int pos_y)
{
	if (game->map->grid[pos_x][pos_y] == 'C' || game->map->grid[pos_x][pos_y] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->bg_img,
			pos_y * SPRITE_SIZE, pos_x * SPRITE_SIZE);
	else if (game->map->grid[pos_x][pos_y] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->e_img,
			pos_y * SPRITE_SIZE, pos_x * SPRITE_SIZE);
}
