/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:27:06 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 00:15:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

t_pool	*init_mem_pool(size_t size)
{
	t_pool	*mem_p;

	mem_p = ft_calloc(1, sizeof(t_pool));
	if (!mem_p)
	{
		printf("error initialising mem_p\n");
		return (NULL);
	}
	mem_p->head = ft_calloc(size, sizeof(char));
	if (!mem_p->head)
	{
		printf("error initialising mem_p->head\n");
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
		printf("mem overflow\n");
		return (NULL);
	}
		
	sub_pool = mem_p->head + mem_p->used;
	mem_p->used += size;
	return(sub_pool);
}

void	free_pool(t_pool *mem_p)
{
	if (mem_p->head)
		free(mem_p->head);
	free(mem_p);
}

void	free_and_exit(t_pool *mem_p, t_game **game, int status, char *msg)
{
	// mlx_destroy_image()
	free_pool(mem_p);
	if (game && (*game)->map && (*game)->map->fd >= 0)
	{
		close((*game)->map->fd);
		(*game)->map->fd = -1;
	}
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
	printf("allocating game memory\n");
	if (!(*game))
		free_and_exit(mem_p, game, 1, "Failed to alloc mem for game.\n");
	(*game)->mlx = mlx_init();
	(*game)->p_x = (*game)->map->p_start_x;
	(*game)->p_y = (*game)->map->p_start_y;
	if (!(*game)->mlx)
		free_and_exit(mem_p, game, 1, "Failed to init mlx.\n");
	(*game)->map = alloc_mem(mem_p, sizeof(t_map));
	if (!(*game)->map)
		free_and_exit(mem_p, game, 1, "Map is not valid / invalid map.\n");
	initialise_map_values((*game)->map, f_map, (*game)->map->fd , 0);
}
