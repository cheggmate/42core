/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:43:03 by jotong            #+#    #+#             */
/*   Updated: 2025/07/31 22:25:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

static void	replace_with_bg(t_game **game, int prev_x, int prev_y)
{
	int	x_adj;
	int	y_adj;

	x_adj = prev_x - (*game)->v_x;
	y_adj = prev_y - (*game)->v_y;
	if (x_adj >= 0 && x_adj <= VIEWPORT_HEIGHT && y_adj >= 0
		&& y_adj <= VIEWPORT_WIDTH)
		mlx_put_image_to_window((*game)->mlx, (*game)->window,
			(*game)->bg_img, prev_y, prev_x);
}

void	render_enemy(t_game **game)
{
	int	mp[2];

	mp[0] = (*game)->enmy_x - (*game)->v_x;
	mp[1] = (*game)->enmy_y - (*game)->v_y;
	if (mp[0] >= 0 && mp[0] < VIEWPORT_HEIGHT
		&& mp[1] >= 0 && mp[1] < VIEWPORT_WIDTH)
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->window,
			(*game)->enmy_img, SPRITE_SIZE * mp[1], SPRITE_SIZE * mp[0]);
	}
}

static void	update_enemy_position(t_game **game, int e_x, int e_y)
{
	(*game)->enmy_x = e_x;
	(*game)->enmy_y = e_y;
	if (e_x == (*game)->p_x && e_y == (*game)->p_y)
		update_lost_game(game);
}

int	move_enemy(t_game **game)
{
	int		try_x;
	int		try_y;
	int		i;
	int		opt;
	int		found_next;

	i = -1;
	found_next = 0;
	while (++i < 4 && found_next == 0)
	{
		opt = rand() % 4;
		try_x = (*game)->enmy_x + (*game)->dir[opt][0];
		try_y = (*game)->enmy_y + (*game)->dir[opt][1];
		if (try_x >= (*game)->map->h || try_x <= 0
			|| try_y <= 0 || try_y >= (*game)->map->w)
			continue ;
		if ((*game)->map->grid[try_x][try_y] == '0')
		{
			replace_with_bg(game, (*game)->enmy_x, (*game)->enmy_y);
			update_enemy_position(game, try_x, try_y);
			break ;
		}
	}
	return (0);
}
