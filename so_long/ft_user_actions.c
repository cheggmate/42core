/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:00:14 by jotong            #+#    #+#             */
/*   Updated: 2025/07/22 22:48:37 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

int	handle_keypress(int keycode, t_game *game, t_pool *mem_p)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		free_and_exit(mem_p, &game->map->fd, 0, "");
	}
	else if (keycode == KEY_W)
		game->p_y--;
	else if (keycode == KEY_A)
		game->p_x--;
	else if (keycode == KEY_S)
		game->p_y++;
	else if (keycode == KEY_D)
		game->p_x++;

	// redraw player;
	// render map;
	return (0);
}
