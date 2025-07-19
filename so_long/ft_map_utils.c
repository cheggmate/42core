/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/20 00:03:51 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

static void	populate_grid(t_map *map, t_pool *mem_p, int fd)
{
	char	*line;
	int		row;
	int		y;

	row = 1;
	line = get_next_line(fd);
	while (line)
	{
		y = 0;
		map->grid[row] = alloc_mem(mem_p, ft_strlen(line) + 1);
		if (ft_strlen(line) != map->w)
			return(1);
		while (*line)
		{
			map->grid[row][y] = *line;
			check_update_element_ctr(mem_p, map, *line);
			y++;
			line++;
		}
		free(line);
		line = get_next_line(fd);
		row += 1;
	}
	free(line);
}

int		get_map_height(char	*f_map)
{
	int		h;
	int		fd;
	char	*line;

	if (!f_map)
		return (0);
	fd = open(f_map, O_RDONLY);
	while((line = get_next_line(fd)) != NULL)
	{
		h++;
		free(line);
	}
	close(fd);
	return (h);
}

t_map	*init_grid(t_pool *mem_p, int width, char *f_map, int fd)
{
	t_map	*map;
	int		i;

	i = 0;
	map = alloc_mem(mem_p, sizeof(t_map));
	if (!map || fd < 0)
		free_end_exit(mem_p, fd, 1);
	map->fd = fd;
	map->h = get_map_height(f_map);
	map->w = width;
	map->c = 0;
	map->exit = 0;
	map->start = 0;
	map->grid = alloc_mem(mem_p, map->h + 1);
	if (!map->grid)
		free_end_exit(mem_p, fd, 1);
	while (i++ < map->w)
	{
		map->grid[i] = alloc_mem(mem_p, map->w + 1);
		if (!map->grid[i])
			free_end_exit(mem_p, fd, 1);
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
		free_end_exit(mem_p, fd, 1);
	fd = open(f_map, O_RDONLY);
	line = get_next_line(fd);
	tmp_width = ft_strlen(line);
	populate_row(map, line);
	map = init_grid(mem_p, tmp_width, f_map, fd);
	if (map->h == 0)
		free_end_exit(mem_p, fd, 1);
	populate_grid(map, mem_p, fd);
	if (map->c == 0)
		free_and_exit(mem_p, fd, 1);
	close(fd);
	
	// connect display
}
