/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_actions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:00:14 by jotong            #+#    #+#             */
/*   Updated: 2025/07/31 22:49:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

void	update_lost_game(t_game **game)
{
	(*game)->lost = 1;
	mlx_string_put((*game)->mlx, (*game)->window, 10, 10, 0xFFFFFF,
		"You lost! try again.");
}

void	print_mvmt(t_game **game)
{
	char	*mvmt_str;
	char	*msg;

	mvmt_str = ft_itoa((*game)->n_mvmts);
	msg = ft_strjoin("Movement count: ", mvmt_str);
	mlx_string_put((*game)->mlx, (*game)->window, 10, 10, 0xFFFFFF, msg);
	free(msg);
	free(mvmt_str);
	msg = NULL;
	mvmt_str = NULL;
}

static void	count_movements(int keycode, t_game **game)
{
	int		x;
	int		y;

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
		if (x == (*game)->enmy_x && y == (*game)->enmy_y)
			update_lost_game(game);
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
	if (keycode == KEY_ESC)
		close_window(game);
	else if ((keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
			|| keycode == KEY_D) && (game->lost == 0 && game->won == 0))
	{
		count_movements(keycode, &game);
		if (game->p_x != prev_x || game->p_y != prev_y)
		{
			if (game->map->grid[prev_x][prev_y] == 'P')
				game->map->grid[prev_x][prev_y] = '0';
			reload_map(&game, prev_x, prev_y);
			print_mvmt(&game);
		}
	}
	return (0);
}
