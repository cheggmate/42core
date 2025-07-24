/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:00:14 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 21:28:25 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
// #include "minilibx_opengl_20191021/mlx.h"
#include "minilibx-linux/mlx.h"

static void	count_movements(int keycode, t_game **game)
{
	int	x;
	int	y;

	x = (*game)->p_x;
	y = (*game)->p_y;
	if (keycode == KEY_A)
		y--;
	else if (keycode == KEY_W)
		x--;	
	else if (keycode == KEY_D)
		y++;
	else if (keycode == KEY_S)
		x++;
	if (x >= 0 && x < (*game)->map->h && y >= 0 && y < (*game)->map->w
		&& (*game)->map->grid[x][y] != '1')
	{
		(*game)->p_x = x;
		(*game)->p_y = y;
		(*game)->n_mvmts += 1;
		ft_printf("movement count: %d\n", (*game)->n_mvmts);
	}
}

int	handle_keypress(int keycode, void *game_in)
{
	int		prev_x;
	int		prev_y;
	t_game	*game;

	game = (t_game *)game_in;
	prev_x = game->p_x;
	prev_y = game->p_y;
	printf("prevx = %d, prevy = %d\n", prev_x, prev_y);
	printf("Key pressed: %c\n", keycode);
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		count_movements(keycode , &game);
		if (game->p_x != prev_x || game->p_y != prev_y)
			reload_map(&game, prev_x, prev_y);
	}
	return (0);
}
