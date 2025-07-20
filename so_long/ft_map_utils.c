/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/20 15:34:58 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	populate_row(t_pool *mem_p, t_map *map, int row, char *line)
{
	int		y;

	y = 0;
	while (*line)
	{
		map->grid[row][y] = *line;
		check_update_element_ctr(mem_p, map, *line);
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
	while (*line)
	{
		map->grid[row] = alloc_mem(mem_p, ft_strlen(line) + 1);
		if (ft_strlen(line) != (size_t)map->w)
			free_and_exit(mem_p, &fd, 1);
		populate_row(mem_p, map, row, line);
		// while (*line)
		// {
		// 	map->grid[row][y] = *line;
		// 	check_update_element_ctr(mem_p, map, *line);
		// 	line++;
		// }
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

	h = 0;
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
		free_and_exit(mem_p, &fd, 1);
	map->fd = fd;
	map->h = get_map_height(f_map);
	map->w = width;
	map->c = 0;
	map->exit = 0;
	map->start = 0;
	map->grid = alloc_mem(mem_p, map->h + 1);
	if (!map->grid)
		free_and_exit(mem_p, &fd, 1);
	while (i++ < map->w)
	{
		map->grid[i] = alloc_mem(mem_p, map->w + 1);
		if (!map->grid[i])
			free_and_exit(mem_p, &fd, 1);
	}
	return (map);
}

void	print_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < map->w)
	{
		while (j++ < map->h)
			ft_printf("%c", map->grid[i][j]);
		ft_printf("\n");
	}
}

t_map	*load_map(char *f_map)
{
	t_map	*map;
	t_pool	*mem_p;
	int		tmp_width;
	int		fd;
	char	*line;

	line = NULL;
	map = NULL;
	tmp_width = 0;
	mem_p = NULL;
	if (!f_map)
		free_and_exit(mem_p, &fd, 1);
	fd = open(f_map, O_RDONLY);
	line = get_next_line(fd);
	tmp_width = ft_strlen(line);
	populate_row(mem_p, map, 0, line);
	map = init_grid(mem_p, tmp_width, f_map, fd);
	if (map->h == 0)
		free_and_exit(mem_p, &fd, 1);
	populate_grid(map, mem_p, fd);
	if (map->c == 0)
		free_and_exit(mem_p, &fd, 1);
	close(fd);
	
	print_map(map);
	// connect display
	return (map);
}
