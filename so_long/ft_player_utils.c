/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:27:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/22 22:38:54 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

void	show_player(t_game *game, int pos_x, int pos_y)
{
	void	*player;
	int		player_edge;

	player_edge = 32;
	player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &player_edge, &player_edge);
	printf("create player sprite\n");
	mlx_put_image_to_window(game->mlx, game->window, player, pos_y * SPRITE_SIZE, pos_x * SPRITE_SIZE);
	printf("Created player.\n");
}
