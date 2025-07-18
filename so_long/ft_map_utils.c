/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/19 00:28:24 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int		get_map_height(char	*f_map)
{
	int		h;
	int		fd;
	char	*line;

	if (!f_map)
		return (0);
	fd = open(f_map, O_RDONLY);
	while(line = get_next_line(fd) != NULL)
	{
		h++;
		free(line);
	}
	close(fd);
	return (h);

}

t_map	*init_grid(t_pool *mem_p, char *f_map)
{
	t_map	*map;
	int		i;

	i = 0;
	map = alloc_mem(mem_p, sizeof(t_map));
	if (!map)
		free_end_exit(mem_p, 1);
	map->h = get_map_height(f_map);
	map->w = ft_strlen(get_next_line(f_map));
	map->grid = alloc_mem(mem_p, map->h + 1);
	if (!map->grid)
		free_end_exit(mem_p, 1);
	while (i++ < map->w)
	{
		map->grid[i] = alloc_mem(mem_p, map->w + 1);
		if (!map->grid[i])
			free_end_exit(mem_p, 1);
	}
	return (map);
}

t_map	*load_map(t_pool *mem_p, char *f_map)
{
	t_map	*map;
	int		tmp_width;

	map = NULL;
	tmp_width = 0;
	if (!f_map)
		return (1);
	map = init_grid(mem_p, f_map);
	if (map->h == 0)
		free_end_exit(mem_p, 1);
	
	
	// check map .ber file exists and is not empty
	// initialise 2D array
	// while parsing input from .ber file, ensure all inputs are valid
	// check only one start position
	// check at least one collectible
	// check for rectangle
	// connect display
}
