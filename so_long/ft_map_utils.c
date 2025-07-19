/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/19 22:28:54 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	populate_row(t_map *map, char *line, int row)
{
	int	y;
	int	width;

	y = 0;
	width = ft_strlen(line);
	if (width != map->w)
		return(1);
	while (*line)
	{
		map->grid[row][y] = *line;
		y++;
		line++;
	}
}

static void	populate_grid(t_map *map, t_pool *mem_p, int fd)
{
	char	*line;
	int		row;

	row = 1;
	line = get_next_line(fd);
	while (line)
	{
		populate_row(map, line, row);
		line = get_next_line(fd);
		row += 1;
	}
}

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

t_map	*init_grid(t_pool *mem_p, int width, char *f_map)
{
	t_map	*map;
	int		i;

	i = 0;
	map = alloc_mem(mem_p, sizeof(t_map));
	if (!map)
		free_end_exit(mem_p, 1);
	map->h = get_map_height(f_map);
	map->w = width;
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
	int		fd;
	char	*line;

	line = NULL;
	map = NULL;
	tmp_width = 0;
	if (!f_map)
		free_end_exit(mem_p, 1);
	fd = open(f_map, O_RDONLY);
	line = get_next_line(fd);
	tmp_width = ft_strlen(line);
	populate_row(map, line);
	map = init_grid(mem_p, tmp_width, f_map);
	if (map->h == 0)
		free_end_exit(mem_p, 1);
	populate_grid(map, mem_p, fd);
	close(fd);
	
	// check map .ber file exists and is not empty
	// initialise 2D array
	// while parsing input from .ber file, ensure all inputs are valid
	// check only one start position
	// check at least one collectible
	// check for rectangle
	// connect display
}
