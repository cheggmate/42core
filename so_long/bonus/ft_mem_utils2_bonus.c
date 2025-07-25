/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:11:24 by jotong            #+#    #+#             */
/*   Updated: 2025/07/26 00:20:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

static void	destroy_animations(t_game **game)
{
	if ((*game)->l1_img)
		mlx_destroy_image((*game)->mlx, (*game)->l1_img);
	if ((*game)->l2_img)
		mlx_destroy_image((*game)->mlx, (*game)->l2_img);
	if ((*game)->l3_img)
		mlx_destroy_image((*game)->mlx, (*game)->l3_img);
	(*game)->l1_img = NULL;
	(*game)->l2_img = NULL;
	(*game)->l3_img = NULL;
}

void	destroy_images(t_game **game)
{
	if (!game || (*game) || (*game)->mlx)
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
	(*game)->p_img = NULL;
	destroy_animations(game);
}
