/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:27:06 by jotong            #+#    #+#             */
/*   Updated: 2025/07/26 00:29:22 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

t_pool	*init_mem_pool(size_t size)
{
	t_pool	*mem_p;

	mem_p = ft_calloc(1, sizeof(t_pool));
	if (!mem_p)
	{
		ft_printf("Failed to initialise mem_p\n");
		return (NULL);
	}
	mem_p->head = ft_calloc(size, sizeof(char));
	if (!mem_p->head)
	{
		ft_printf("Failed to initialise mem_p->head\n");
		return (NULL);
	}
	mem_p->total = size;
	mem_p->used = 0;
	return (mem_p);
}

void	*alloc_mem(t_pool *mem_p, size_t size)
{
	void	*sub_pool;

	sub_pool = NULL;
	if (!mem_p || !mem_p->head)
		return (NULL);
	if (mem_p->used + size > mem_p->total)
	{
		ft_printf("Mem overflow\n");
		return (NULL);
	}
	sub_pool = mem_p->head + mem_p->used;
	mem_p->used += size;
	return (sub_pool);
}

void	free_pool(t_pool *mem_p)
{
	if (mem_p->head)
		free(mem_p->head);
	free(mem_p);
}

void	free_and_exit(t_pool *mem_p, t_game **game, int status, char *msg)
{
	if (game && *game && (*game)->map && (*game)->map->fd >= 0)
	{
		close((*game)->map->fd);
		(*game)->map->fd = -1;
	}
	destroy_images(game);
	free_pool(mem_p);
	if (status == 1)
	{
		write(2, "Error\n", 6);
		write(2, msg, ft_strlen(msg));
		exit(EXIT_FAILURE);
	}
	else
	{
		(void)msg;
		exit(EXIT_SUCCESS);
	}
}

void	init_game(t_pool *mem_p, t_game **game, char *f_map)
{
	*game = alloc_mem(mem_p, sizeof(t_game));
	if (!(*game))
		free_and_exit(mem_p, game, 1, "Failed to alloc mem for game.\n");
	(*game)->mem_p = mem_p;
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		free_and_exit(mem_p, game, 1, "Failed to init mlx.\n");
	(*game)->c_count = 0;
	(*game)->mp = f_map;
	(*game)->n_mvmts = 0;
	(*game)->v_x = 0;
	(*game)->v_y = 0;
	(*game)->view_w = 0;
	(*game)->view_h = 0;
	(*game)->ani_val = 0;
	(*game)->map = alloc_mem(mem_p, sizeof(t_map));
	if (!(*game)->map)
		free_and_exit(mem_p, game, 1, "Map is not valid / invalid map.\n");
	initialise_map_values(game, f_map);
}
