/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:11:24 by jotong            #+#    #+#             */
/*   Updated: 2025/07/31 22:27:41 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

void	free_mlx(t_game **game)
{
	if ((*game)->mlx && (*game)->window)
	{
		mlx_destroy_window((*game)->mlx, (*game)->window);
		(*game)->window = NULL;
	}
	if ((*game)->mlx)
	{
		mlx_destroy_display((*game)->mlx);
		free((*game)->mlx);
		(*game)->mlx = NULL;
	}
}

static void	destroy_animations(t_game **game)
{
	if ((*game)->l1_img)
		mlx_destroy_image((*game)->mlx, (*game)->l1_img);
	if ((*game)->l2_img)
		mlx_destroy_image((*game)->mlx, (*game)->l2_img);
	if ((*game)->l3_img)
		mlx_destroy_image((*game)->mlx, (*game)->l3_img);
	if ((*game)->enmy_img)
		mlx_destroy_image((*game)->mlx, (*game)->enmy_img);
	(*game)->l1_img = NULL;
	(*game)->l2_img = NULL;
	(*game)->l3_img = NULL;
	(*game)->enmy_img = NULL;
}

void	destroy_images(t_game **game)
{
	if (!game || !(*game) || !(*game)->mlx)
		return ;
	if ((*game)->p_img)
		mlx_destroy_image((*game)->mlx, (*game)->p_img);
	if ((*game)->w_img)
		mlx_destroy_image((*game)->mlx, (*game)->w_img);
	if ((*game)->bg_img)
		mlx_destroy_image((*game)->mlx, (*game)->bg_img);
	if ((*game)->e_img)
		mlx_destroy_image((*game)->mlx, (*game)->e_img);
	if ((*game)->c_img)
		mlx_destroy_image((*game)->mlx, (*game)->c_img);
	if ((*game)->e2_img)
		mlx_destroy_image((*game)->mlx, (*game)->e2_img);
	(*game)->w_img = NULL;
	(*game)->bg_img = NULL;
	(*game)->e_img = NULL;
	(*game)->e2_img = NULL;
	(*game)->p_img = NULL;
	(*game)->c_img = NULL;
	destroy_animations(game);
}

void	init_dir(t_game **game, t_pool *mem_p)
{
	int	i;

	i = -1;
	(*game)->dir = alloc_mem(mem_p, 4 * sizeof(int *));
	if (!(*game)->dir)
		free_and_exit(mem_p, game, 1, "Failed to allocate memory.\n");
	while (++i < 4)
		(*game)->dir[i] = alloc_mem(mem_p, 2 * sizeof(int));
	i = -1;
	(*game)->dir[0][0] = 0;
	(*game)->dir[0][1] = 1;
	(*game)->dir[1][0] = 1;
	(*game)->dir[1][1] = 0;
	(*game)->dir[2][0] = 0;
	(*game)->dir[2][1] = -1;
	(*game)->dir[3][0] = -1;
	(*game)->dir[3][1] = 0;
}

void	init_more_game_values(t_game **game)
{
	(*game)->bg_img = NULL;
	(*game)->c_img = NULL;
	(*game)->e_img = NULL;
	(*game)->e2_img = NULL;
	(*game)->enmy_img = NULL;
	(*game)->p_img = NULL;
	(*game)->w_img = NULL;
	(*game)->l1_img = NULL;
	(*game)->l2_img = NULL;
	(*game)->l3_img = NULL;
}
