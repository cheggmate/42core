/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:57:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/25 23:08:56 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

void	calculate_viewable_area(t_game **game)
{
	if ((*game)->map->w > VIEWPORT_WIDTH)
	{
		(*game)->v_y = (*game)->p_y - VIEWPORT_WIDTH / 2;
		if ((*game)->v_y < 0)
			(*game)->v_y = 0;
		if ((*game)->v_y + VIEWPORT_WIDTH > (*game)->map->w)
			(*game)->v_y = (*game)->map->w - VIEWPORT_WIDTH;
	}
	else
		(*game)->v_y = 0;
	if ((*game)->map->h > VIEWPORT_HEIGHT)
	{
		(*game)->v_x = (*game)->p_x - VIEWPORT_HEIGHT / 2;
		if ((*game)->v_x < 0)
			(*game)->v_x = 0;
		if ((*game)->v_x + VIEWPORT_HEIGHT > (*game)->map->h)
			(*game)->v_x = (*game)->map->h - VIEWPORT_HEIGHT;
	}
	else
		(*game)->v_x = 0;
}

static void	put_relevant_image(t_game **game, int *ctr, int *mp, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->w_img,
			SPRITE_SIZE * ctr[1], SPRITE_SIZE * ctr[0]);
	if (tile == 'C')
		mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->c_img,
			SPRITE_SIZE * ctr[1], SPRITE_SIZE * ctr[0]);
	if (tile == 'E' && (*game)->c_count == (*game)->map->c
		&& mp[0] == (*game)->p_x && mp[1] == (*game)->p_y)
		mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->e2_img,
			SPRITE_SIZE * ctr[1], SPRITE_SIZE * ctr[0]);
	else if (tile == 'E')
		mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->e_img,
			SPRITE_SIZE * ctr[1], SPRITE_SIZE * ctr[0]);
	if (tile == '0')
		mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->bg_img,
			SPRITE_SIZE * ctr[1], SPRITE_SIZE * ctr[0]);
}

void	render_viewable_map(t_game **game)
{
	int		mp[2];
	int		ctr[2];
	char	tile;

	ctr[0] = 0;
	while (ctr[0] < (*game)->view_h)
	{
		ctr[1] = 0;
		while (ctr[1] < (*game)->view_w)
		{
			mp[0] = (*game)->v_x + ctr[0];
			mp[1] = (*game)->v_y + ctr[1];
			if (mp[0] >= 0 && mp[0] < (*game)->map->h && mp[1] >= 0
				&& mp[1] < (*game)->map->w)
			{
				tile = (*game)->map->grid[mp[0]][mp[1]];
				put_relevant_image(game, ctr, mp, tile);
			}
			ctr[1]++;
		}
		ctr[0]++;
	}
}

void	reload_map(t_game **game, int prev_x, int prev_y)
{
	calculate_viewable_area(game);
	if ((*game)->map->grid[prev_x][prev_y] == 'C')
	{
		(*game)->c_count += 1;
		(*game)->map->grid[prev_x][prev_y] = '0';
	}
	render_viewable_map(game);
	redraw_player(*game);
}

void	set_view_dimensions(t_game **game)
{
	if ((*game)->map->w < VIEWPORT_WIDTH)
		(*game)->view_w = (*game)->map->w;
	else
		(*game)->view_w = VIEWPORT_WIDTH;
	if ((*game)->map->h < VIEWPORT_HEIGHT)
		(*game)->view_h = (*game)->map->h;
	else
		(*game)->view_h = VIEWPORT_HEIGHT;
}
