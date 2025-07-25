/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/26 01:16:03 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

static void	reload(t_game **game)
{
	reload_map(game, (*game)->p_x, (*game)->p_y);
	print_mvmt(game);
}

static void	load_sprites(t_game **game, int scenario)
{
	void	*img;

	if (scenario == 1)
		img = (*game)->l1_img;
	else if (scenario == 2)
		img = (*game)->l2_img;
	else
		img = (*game)->l3_img;
	mlx_put_image_to_window((*game)->mlx, (*game)->window, img, 85, 30);
	mlx_put_image_to_window((*game)->mlx, (*game)->window, img, 250, 250);
}

int	change_ani(t_game **game)
{
	(*game)->ani_val += 1;
	if ((*game)->ani_val < 10)
		return (0);
	if ((*game)->ani_val > ((*game)->map->w * SPRITE_SIZE))
		(*game)->ani_val = 1;
	if ((*game)->ani_val % 30 == 0)
	{
		reload(game);
		load_sprites(game, 3);
	}
	else if ((*game)->ani_val % 20 == 0)
	{
		reload(game);
		load_sprites(game, 2);
	}
	else
	{
		reload(game);
		load_sprites(game, 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		return (write(2, "Error\nincorrect number of inputs!\n", 34), 1);
	check_asset_list();
	load_map(argv[1], &game);
	mlx_loop_hook(game->mlx, change_ani, &game);
	mlx_loop(game->mlx);
	return (0);
}
