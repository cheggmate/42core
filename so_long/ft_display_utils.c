/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:42:19 by jotong            #+#    #+#             */
/*   Updated: 2025/07/21 00:24:52 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

static int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

static void	*create_window(t_pool *mem_p, t_map *map, void *mlx)
{
	void	*window;
	int		width;
	int		height;

	width = map->w * SPRITE_SIZE;
	height = map->h * SPRITE_SIZE;
	window = mlx_new_window(mlx, width, height, "so_long");
	if (!window)
		free_and_exit(mem_p, &map->fd, 1);
	return (window);
}

static void	show_images(t_map *map, t_game *game)
{
	void	*player;
	int		pic_width;
	int		pic_height;

	player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &pic_width, &pic_height);
	mlx_put_image_to_window(game->mlx, game->window, player, map->p_start_x * SPRITE_SIZE, map->p_start_y * SPRITE_SIZE);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, 17, 0, close_window, game); // 17 = destroy Notify activity
}

void	render_map(t_pool *mem_p, t_map *map, t_game *game)
{
	game = alloc_mem(mem_p, sizeof(t_game));
	if (!game)
		free_and_exit(mem_p, &map->fd, 1);
	game->mlx = mlx_init();
	game->p_x = map->p_start_x;
	game->p_y = map->p_start_y;
	if (!game->mlx)
		free_and_exit(mem_p, &map->fd, 1);
	game->window = create_window(mem_p, map, game->mlx);
	show_images(map, game);
}
