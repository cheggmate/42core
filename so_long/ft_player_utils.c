/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:27:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/27 17:15:03 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#ifdef __APPLE__
# include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "minilibx-linux/mlx.h"
#endif

void	show_player(t_game *game)
{
	void	*player;
	int		player_edge;

	player_edge = 32;
	if (!game->p_img)
	{
		player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
				&player_edge, &player_edge);
		game->p_img = player;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->p_img,
		(game->p_y - game->v_y) * SPRITE_SIZE,
		(game->p_x - game->v_x) * SPRITE_SIZE);
}

void	redraw_player(t_game *game)
{
	if (game->map->grid[game->p_x][game->p_y] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->e2_img,
			(game->p_y - game->v_y) * SPRITE_SIZE,
			(game->p_x - game->v_x) * SPRITE_SIZE);
		if (game->c_count == game->map->c)
			game->won += 1;
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, game->p_img,
			(game->p_y - game->v_y) * SPRITE_SIZE,
			(game->p_x - game->v_x) * SPRITE_SIZE);
	if ((game->c_count == game->map->c
			&& game->map->grid[game->p_x][game->p_y] == 'E')
			|| game->won == 1)
	{
		mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF,
			" Congrats you won!!!!!");
	}
}
