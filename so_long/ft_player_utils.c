/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:27:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/24 23:51:51 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#ifdef __APPLE__
	#include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
	#include "minilibx-linux/mlx.h"
#endif

void	show_player(t_game *game)
{
	void	*player;
	int		player_edge;

	player_edge = 32;
	player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
		&player_edge, &player_edge);
	game->p_img = player;
	printf("create player sprite\n");
	mlx_put_image_to_window(game->mlx, game->window, player,
		(game->p_y - game->v_y) * SPRITE_SIZE,
		(game->p_x - game->v_x) * SPRITE_SIZE);
	printf("Created player.\n");
}

void	redraw_player(t_game *game)
{
	printf("redraw player: p_x = %d, p_y = %d, tile = %c\n", game->p_x, game->p_y, game->map->grid[game->p_x][game->p_y]);
	printf("vx = %d, vy = %d\n", game->v_x, game->v_y);

	if (game->map->grid[game->p_x][game->p_y] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->e2_img,
			(game->p_y - game->v_y) * SPRITE_SIZE,
			(game->p_x - game->v_x) * SPRITE_SIZE);
		if (game->c_count == game->map->c)
		{
			mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF,
			"🎉 Congrats you won!!!🎉");
		}
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, game->p_img,
			(game->p_y - game->v_y) * SPRITE_SIZE,
			(game->p_x - game->v_x) * SPRITE_SIZE);
}
