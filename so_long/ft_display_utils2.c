/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:57:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/25 00:14:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#ifdef __APPLE__
	#include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
	#include "minilibx-linux/mlx.h"
#endif

void	calculate_viewable_area(t_game **game)
{
	printf("(Calculated viewable area) p_x : %d, p_y : %d\n", (*game)->p_x , (*game)->p_y);
	printf("(Calculated viewable area before) x_x : %d, x_y : %d\n", (*game)->v_x , (*game)->v_y);
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
	
	printf("(Calculated viewable area after) x_x : %d, x_y : %d\n", (*game)->v_x , (*game)->v_y);
}

void	render_viewable_map(t_game **game)
{
	int		m_x;
	int		m_y;
	int		i;
	int		j;
	char	tile;

	i = 0;
	printf("rendering viewable map\n");
	while (i <  (*game)->view_h)
	{
		j = 0;
		while (j < (*game)->view_w)
		{
			m_x = (*game)->v_x + i;
			m_y = (*game)->v_y + j;
			if (m_x >= 0 && m_x < (*game)->map->h && m_y >= 0 && m_y < (*game)->map->w)
			{
				tile = (*game)->map->grid[m_x][m_y];
				if (tile == '1')
					mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->w_img, SPRITE_SIZE * j, SPRITE_SIZE * i);
				if (tile == 'C')
					mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->c_img, SPRITE_SIZE * j, SPRITE_SIZE * i);
				if (tile == 'E' && (*game)->c_count == (*game)->map->c)
					mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->e2_img, SPRITE_SIZE * j, SPRITE_SIZE * i);
				else if (tile == 'E')

				mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->e_img, SPRITE_SIZE * j, SPRITE_SIZE * i);
				if (tile == '0')
					mlx_put_image_to_window((*game)->mlx, (*game)->window, (*game)->bg_img, SPRITE_SIZE * j, SPRITE_SIZE * i);
			}
			j++;
		}
		i++;
	}	
}

void	reload_map(t_game **game, int prev_x, int prev_y)
{
	calculate_viewable_area(game);
	printf("game p_x : %d, game p_y: %d\n", (*game)->p_x, (*game)->p_y);
	if ((*game)->map->grid[prev_x][prev_y] == 'C')
	{
		(*game)->c_count += 1;
		(*game)->map->grid[prev_x][prev_y] = '0';
	}
	// if ((*game)->map->grid[prev_x][prev_y] == 'P')
	// 	(*game)->map->grid[prev_x][prev_y] = '0';
	render_viewable_map(game);
	// redraw_tile(*game, prev_x, prev_y);
	redraw_player(*game);
}

void	redraw_tile(t_game *game, int pos_x, int pos_y)
{
	if (game->map->grid[pos_x][pos_y] == 'C' || game->map->grid[pos_x][pos_y] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->bg_img,
		(pos_y - game->v_y) * SPRITE_SIZE, (pos_x - game->v_x) * SPRITE_SIZE);
	else if (game->map->grid[pos_x][pos_y] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->e_img,
			(pos_y - game->v_y) * SPRITE_SIZE, (pos_x - game->v_x) * SPRITE_SIZE);
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
