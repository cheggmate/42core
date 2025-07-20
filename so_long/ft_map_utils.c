/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/20 22:40:09 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	populate_row(t_pool *mem_p, t_map *map, int row, char *line)
{
	int		y;

	y = 0;
	if (!(map->grid[row]))
		free_and_exit(mem_p, &map->fd, 1);
	while (*line)
	{
		if (*line != '\n')
			map->grid[row][y] = *line;
		printf("%c ", map->grid[row][y]);
		check_update_element_ctr(mem_p, map, *line);
		y++;
		line++;
	}
	map->grid[row][y] = '\0';
}

static void	populate_grid(t_map *map, t_pool *mem_p, int fd)
{
	char	*line;
	int		row;

	row = 1;
	while (row < map->h)
	{
		line = get_next_line(fd);
		printf("line is %s\n", line);
		if (!line)
		{
			printf("found an empty line at row %d\n", row);
			break ;
		}
		if ((ft_strlen(line) != (size_t)map->w && row < map->h - 1) || (ft_strlen(line) != ((size_t)(map->w) - 1) && row == map->h - 1))
			free_and_exit(mem_p, &fd, 1);
		populate_row(mem_p, map, row, line);
		free(line);
		print_map(map);
		row++;
	}
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
	map->grid = alloc_mem(mem_p, sizeof(char *) * (map->h + 1));
	if (!map->grid)
		free_and_exit(mem_p, &fd, 1);
	while (i < map->h)
	{
		map->grid[i] = alloc_mem(mem_p, sizeof(char) * (map->w + 1));
		if (!(map->grid[i]))
			free_and_exit(mem_p, &fd, 1);
		i++;
	}
	return (map);
}

void	print_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_printf("%c", map->grid[i][j]);
			j++;
		}
		i++;
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
	mem_p = init_mem_pool(POOL_SIZE);
	if (!f_map)
		free_and_exit(mem_p, &fd, 1);
	fd = open(f_map, O_RDONLY);
	line = get_next_line(fd);
	tmp_width = ft_strlen(line);
	map = init_grid(mem_p, tmp_width, f_map, fd);
	if (map->h == 0)
		free_and_exit(mem_p, &fd, 1);
	populate_row(mem_p, map, 0, line);
	populate_grid(map, mem_p, fd);
	if (map->c == 0)
		free_and_exit(mem_p, &fd, 1);
	close(fd);
	print_map(map);			// remove before submission
	return (map);
}
