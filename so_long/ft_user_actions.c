/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:00:14 by jotong            #+#    #+#             */
/*   Updated: 2025/07/24 23:56:49 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#ifdef __APPLE__
	#include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
	#include "minilibx-linux/mlx.h"
#endif

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
	printf("x : %d, y : %d\n", x, y);
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

	printf("(handle keypress) v_x : %d, v_y : %d\n", game->v_x , game->v_y);
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		count_movements(keycode , &game);     
		           
		if (game->p_x != prev_x || game->p_y != prev_y)
		{
			if (game->map->grid[prev_x][prev_y] == 'P')
				game->map->grid[prev_x][prev_y] = '0';
			reload_map(&game, prev_x, prev_y);
		}
			
	}
	return (0);
}
