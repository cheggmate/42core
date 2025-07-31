/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:27:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/27 17:28:26 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

void	show_enemy(t_game *game)
{
	void	*enemy;
	int		enemy_edge;
	int		enemy_x;
	int		enemy_y;

	enemy_edge = 32;
	enemy = mlx_xpm_file_to_image(game->mlx, "assets/enemy.xpm",
			&enemy_edge, &enemy_edge);
	game->enmy_img = enemy;
	enemy_x = (game->enmy_x - game->v_x);
	enemy_y = (game->enmy_y - game->v_y);
	if (enemy_y >= 0 && enemy_y < game->view_w && enemy_x >= 0
		&& enemy_x < game->view_h && game->map->grid[enemy_x][enemy_y] == '0')
		mlx_put_image_to_window(game->mlx, game->window, enemy,
			(game->enmy_y - game->v_y) * SPRITE_SIZE,
			(game->enmy_x - game->v_x) * SPRITE_SIZE);
}

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
		mlx_string_put(game->mlx, game->window, 200, 10, 0xFFFFFF,
			" Congrats you won!!!!!");
	}
}
