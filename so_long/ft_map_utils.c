/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/22 22:10:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	populate_row(t_pool *mem_p, t_map *map, int row, char *line)
{
	int		pos[2];

	pos[0] = row;
	pos[1] = 0;
	if (!(map->grid[row]))
		free_and_exit(mem_p, &map->fd, 1, "Failed to alloc mem for grid.\n");
	while (*line)
	{
		printf("row = %d, map->h-1 = %d, *line = %d\n",row, map->h-1, *line);
		if (((row == 0 || row == map->h - 1) && *line != '1'
			&& pos[1] != map->w - 1) || ((pos[1] == 0 || pos[1] == map->w - 2)
			&& *line != '1'))
			free_and_exit(mem_p, &map->fd, 1, "Map not enclosed by walls.\n");
		if (*line != '\n')
			map->grid[row][pos[1]] = *line;
		check_update_element_ctr(mem_p, map, *line, pos);
		pos[1]++;
		line++;
	}
	map->grid[row][pos[1]] = '\0';
}

static void	populate_grid(t_map *map, t_pool *mem_p, int fd)
{
	char	*line;
	int		row;

	row = 1;
	while (row < map->h)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("found an empty line at row %d\n", row);
			break ;
		}
		if ((ft_strlen(line) != (size_t)map->w && row < map->h - 1)
			|| (ft_strlen(line) != ((size_t)(map->w) - 1) && row == map->h - 1))
			free_and_exit(mem_p, &fd, 1, "Map is not rectangular.\n");
		populate_row(mem_p, map, row, line);
		free(line);
		row++;
	}
}

static void	initialise_map_values(t_map *map, char *f_map, int fd, int width)
{
	map->fd = fd;
	map->w = width;
	map->h = get_map_height(f_map);
	map->c = 0;
	map->exit = 0;
	map->start = 0;
	map->p_start_x = 0;
	map->p_start_y = 0;
}

t_map	*init_grid(t_pool *mem_p, int width, char *f_map, int fd)
{
	t_map	*map;
	int		i;

	i = 0;
	map = alloc_mem(mem_p, sizeof(t_map));
	if (!map || fd < 0)
		free_and_exit(mem_p, &fd, 1, "Map is not valid / invalid map.\n");
	initialise_map_values(map, f_map, fd, width);
	map->grid = alloc_mem(mem_p, sizeof(char *) * (map->h + 1));
	if (!map->grid)
		free_and_exit(mem_p, &fd, 1, "Failed to alloc mem for grid.\n");
	while (i < map->h)
	{
		map->grid[i] = alloc_mem(mem_p, sizeof(char) * (map->w + 1));
		if (!(map->grid[i]))
			free_and_exit(mem_p, &fd, 1, "Failed to alloc mem for grid.\n");
		i++;
	}
	return (map);
}

t_map	*load_map(char *f_map, t_game **game)
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
		free_and_exit(mem_p, &fd, 1, "failed to allocate memory pool.\n");
	fd = open(f_map, O_RDONLY);
	line = get_next_line(fd);
	tmp_width = ft_strlen(line);
	map = init_grid(mem_p, tmp_width, f_map, fd);
	if (map->h == 0)
		free_and_exit(mem_p, &fd, 1, "Empty map file provided.\n");
	populate_row(mem_p, map, 0, line);
	populate_grid(map, mem_p, fd);
	if (map->c == 0)
		free_and_exit(mem_p, &fd, 1, "No collectibles found.\n");
	close(fd);
	print_map(map);			// remove before submission
	render_map(&mem_p, map, game);
	return (map);
}
