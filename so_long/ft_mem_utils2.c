/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:11:24 by jotong            #+#    #+#             */
/*   Updated: 2025/07/27 17:10:20 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#ifdef __APPLE__
# include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "minilibx-linux/mlx.h"
#endif

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
}

void	free_mlx(t_game **game)
{
	if ((*game)->mlx && (*game)->window)
	{
		mlx_destroy_window((*game)->mlx, (*game)->window);
		(*game)->mlx = NULL;
		(*game)->window = NULL;
	}
}
