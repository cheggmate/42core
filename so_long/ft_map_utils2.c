/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:14:39 by jotong            #+#    #+#             */
/*   Updated: 2025/07/22 00:53:35 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void check_update_element_ctr(t_pool *mem_p, t_map *map, char c, int *pos)
{
	if (c == 'C')
		map->c += 1;
	else if (c == 'P')
	{
		map->start += 1;
		map->p_start_x = pos[0];
		map->p_start_y = pos[1];
	}
	else if (c == 'E')
		map->exit += 1;
	if (map->start > 1)
		free_and_exit(mem_p, &map->fd, 1, "More than one start pos found.\n");
	else if (map->exit > 1)
		free_and_exit(mem_p, &map->fd, 1, "More than one exit found.\n");
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

int	check_asset_exist(char *f_name)
{
	int	fd;
	int	result;

	fd = open(f_name, O_RDONLY);
	result = fd;
	close(fd);
	return (result);
}
