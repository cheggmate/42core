/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 00:14:38 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	populate_row(t_pool *mem_p, t_game **game, int row, char *line)
{
	int		pos[2];

	pos[0] = row;
	pos[1] = 0;
	if (!((*game)->map->grid[row]))
		free_and_exit(mem_p, game, 1, "Failed to alloc mem for grid.\n");
	while (*line)
	{
		if (((row == 0 || row == (*game)->map->h - 1) && *line != '1'
			&& pos[1] != (*game)->map->w - 1)
			|| ((pos[1] == 0 || pos[1] == (*game)->map->w - 2) && *line != '1'))
			free_and_exit(mem_p, game, 1, "Map not enclosed by walls.\n");
		if (*line != '\n')
			(*game)->map->grid[row][pos[1]] = *line;
		check_update_element_ctr(mem_p, game, *line, pos);
		pos[1]++;
		line++;
	}
	(*game)->map->grid[row][pos[1]] = '\0';
}

static void	populate_grid(t_game **game, t_pool *mem_p, int fd)
{
	char	*line;
	int		row;

	row = 1;
	while (row < (*game)->map->h)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("found an empty line at row %d\n", row);
			break ;
		}
		if ((ft_strlen(line) != (size_t)(*game)->map->w
			&& row < (*game)->map->h - 1)
			|| (ft_strlen(line) != ((size_t)((*game)->map->w) - 1)
			&& row == (*game)->map->h - 1))
			free_and_exit(mem_p, game, 1, "Map is not rectangular.\n");
		populate_row(mem_p, game, row, line);
		free(line);
		row++;
	}
}

void	initialise_map_values(t_map *map, char *f_map, int fd, int width)
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

void	init_grid(t_pool *mem_p, char *f_map, t_game **game)
{
	int		i;
	int		width;
	char	*line;

	i = 0;
	(*game)->map->fd = open(f_map, O_RDONLY);
	line = get_next_line((*game)->map->fd );
	width = ft_strlen(line);
	(*game)->map->w = width;
	(*game)->map->grid = alloc_mem(mem_p, sizeof(char *) * ((*game)->map->h + 1));
	if (!(*game)->map->grid)
		free_and_exit(mem_p, game, 1, "Failed to alloc mem for grid.\n");
	while (i < (*game)->map->h)
	{
		(*game)->map->grid[i] = alloc_mem(mem_p, sizeof(char) * ((*game)->map->w + 1));
		if (!((*game)->map->grid[i]))
			free_and_exit(mem_p, game, 1, "Failed to alloc mem for grid.\n");
		i++;
	}
}

void	load_map(char *f_map, t_game **game)
{
	t_pool	*mem_p;
	char	*line;

	line = NULL;
	mem_p = init_mem_pool(POOL_SIZE);
	if (!f_map)
		free_and_exit(mem_p, game, 1, "failed to allocate memory pool.\n");
	// fd = open(f_map, O_RDONLY);
	// line = get_next_line(fd);
	// tmp_width = ft_strlen(line);
	init_game(&mem_p, game, f_map);
	init_grid(mem_p, f_map, game);
	if ((*game)->map->h == 0)
		free_and_exit(mem_p, game, 1, "Empty map file provided.\n");
	populate_row(mem_p, game, 0, line);
	populate_grid(game, mem_p, (*game)->map->fd);
	if ((*game)->map->c == 0)
		free_and_exit(mem_p, game, 1, "No collectibles found.\n");
	close((*game)->map->fd);
	print_map((*game)->map);			// remove before submission
	render_map(&mem_p, (*game)->map, game);
}
