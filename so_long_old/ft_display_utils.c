/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:42:19 by jotong            #+#    #+#             */
/*   Updated: 2025/07/27 17:10:43 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#ifdef __APPLE__
# include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "minilibx-linux/mlx.h"
#endif

int	close_window(void *game)
{
	t_game	*game_tmp;

	game_tmp = (t_game *)game;
	if (game_tmp && game_tmp->mlx && game_tmp->window)
	{
		mlx_destroy_window(game_tmp->mlx, game_tmp->window);
		ft_printf("freeing memory after destroying window\n");
		game_tmp->window = NULL;
	}
	free_and_exit(game_tmp->mem_p, &game_tmp, 0, "Window closed.");
	return (0);
}

static void	*create_window(t_pool *mem_p, t_game **game, void *mlx)
{
	int		width;
	int		height;

	width = ((*game)->view_w) * SPRITE_SIZE;
	height = ((*game)->view_h) * SPRITE_SIZE;
	(*game)->window = mlx_new_window(mlx, width, height, "so_long");
	if (!(*game)->window)
		free_and_exit(mem_p, game, 1, "Failed to open new window.\n");
	return ((*game)->window);
}

void	show_images(t_game *game)
{
	show_background(game);
	show_walls(game);
	show_exit(game, 1);
	show_collectible(game);
	show_player(game);
}

int	handle_close(void *game_in)
{
	t_game	*game;

	game = (t_game *)game_in;
	close_window(game);
	return (0);
}

void	render_map(t_pool **mem_p, t_game **game)
{
	(*game)->window = create_window(*mem_p, game, (*game)->mlx);
	show_images((*game));
	render_viewable_map(game);
	mlx_key_hook((*game)->window, handle_keypress, *game);
	mlx_hook((*game)->window, 17, 0, handle_close, *game);
}
