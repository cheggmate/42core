/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:27:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 19:20:03 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
// #include "minilibx_opengl_20191021/mlx.h"
#include "minilibx-linux/mlx.h"

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
		game->p_y * SPRITE_SIZE, game->p_x * SPRITE_SIZE);
	printf("Created player.\n");
}

void	redraw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->p_img,
		game->p_y * SPRITE_SIZE,  game->p_x * SPRITE_SIZE);
}
