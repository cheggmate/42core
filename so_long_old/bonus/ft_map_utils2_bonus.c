/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:14:39 by jotong            #+#    #+#             */
/*   Updated: 2025/07/25 22:52:23 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	check_update_element_ctr(t_pool *mem_p, t_game **game, char c, int *pos)
{
	if (c == 'C')
		(*game)->map->c += 1;
	else if (c == 'P')
	{
		(*game)->map->start += 1;
		(*game)->map->p_start_x = pos[0];
		(*game)->map->p_start_y = pos[1];
		(*game)->p_x = pos[0];
		(*game)->p_y = pos[1];
	}
	else if (c == 'E')
		(*game)->map->exit += 1;
	if ((*game)->map->start > 1)
		free_and_exit(mem_p, game, 1, "More than one start pos found.\n");
	else if ((*game)->map->exit > 1)
		free_and_exit(mem_p, game, 1, "More than one exit found.\n");
}

void	print_map(t_map *map)
{
	int	i;
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

void	get_map_edges(t_game **game, char *f_map)
{
	int		h;
	int		w;
	int		fd;
	char	*line;

	h = 0;
	w = 0;
	if (!f_map)
		return ;
	fd = open(f_map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\n')
			break ;
		w = ft_strlen(line);
		h++;
		free(line);
		line = get_next_line(fd);
	}
	(*game)->map->h = h;
	(*game)->map->w = w;
	free(line);
	close(fd);
}

int	check_asset_exist(char *f_name)
{
	int	fd;
	int	result;

	fd = open(f_name, O_RDONLY);
	result = fd;
	close(fd);
	return (result);
}
