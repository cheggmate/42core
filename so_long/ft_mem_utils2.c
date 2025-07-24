/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:11:24 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 22:31:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
// #include "minilibx_opengl_20191021/mlx.h"
#include "minilibx-linux/mlx.h"

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
}

