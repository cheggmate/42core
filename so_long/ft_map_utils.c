/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:06:18 by jotong            #+#    #+#             */
/*   Updated: 2025/07/23 20:20:02 by jotong           ###   ########.fr       */
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
			&& pos[1] != (*game)->map->w)
			|| ((pos[1] == 0 || pos[1] == (*game)->map->w - 1) && *line != '1'))
			free_and_exit(mem_p, game, 1, "Map not enclosed by walls.\n");
		printf("*line is %c, pos[1] is %d\n", *line, pos[1]);
		if (*line != '\n')
			(*game)->map->grid[row][pos[1]] = *line;
		else if (*line == '\n')
		{
			(*game)->map->grid[row][pos[1]] = '\0';
			break;
		}
		check_update_element_ctr(mem_p, game, *line, pos);
		printf("after checking update element ctr\n");
		pos[1]++;
		line++;
	}
	printf("added value into grid\n");
}

static void	populate_grid(t_game **game, t_pool *mem_p, int fd)
{
	char	*line;
	int		row;
	size_t	len;

	row = 1;
	while (row < (*game)->map->h)
	{
		if (!line)
		{
			printf("found an empty line at row %d\n", row);
			break ;
		}
		line = get_next_line(fd);
		len = ft_strlen(line) - 1;
		printf("checking width\n");
		printf("len = %zu\n", len);
		printf("width = %d\n", (*game)->map->w);
		if ((len != (size_t)(*game)->map->w && row < (*game)->map->h - 1)
			|| (len != ((size_t)(*game)->map->w - 1)
			&& row == (*game)->map->h - 1))
			free_and_exit(mem_p, game, 1, "Map is not rectangular.\n");
		printf("pass if check, populating rrow\n");
		populate_row(mem_p, game, row, line);
		free(line);
		row++;
	}
}

void	initialise_map_values(t_game **game, char *f_map)
{
	get_map_edges(game, f_map);
	(*game)->map->c = 0;
	(*game)->map->exit = 0;
	(*game)->map->start = 0;
	(*game)->map->p_start_x = 0;
	(*game)->map->p_start_y = 0;
	// close(fd);
	// fd = -1;
}

void	init_grid(t_pool *mem_p, char *f_map, t_game **game)
{
	int		i;

	i = 0;
	(*game)->map->fd = open(f_map, O_RDONLY);
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
	init_game(mem_p, game, f_map);
	init_grid(mem_p, f_map, game);
	printf("init grid complete\n");
	if ((*game)->map->h == 0)
		free_and_exit(mem_p, game, 1, "Empty map file provided.\n");
	line = get_next_line((*game)->map->fd);
	populate_row(mem_p, game, 0, line);
	printf("populate row completed\n");
	populate_grid(game, mem_p, (*game)->map->fd);
	printf("populate grid completed\n");
	if ((*game)->map->c == 0)
		free_and_exit(mem_p, game, 1, "No collectibles found.\n");
	close((*game)->map->fd);
	print_map((*game)->map);			// remove before submission
	render_map(&mem_p, (*game)->map, game);
	printf("p_x: %d and p_y: %d\n", (*game)->p_x, (*game)->p_y);
}
