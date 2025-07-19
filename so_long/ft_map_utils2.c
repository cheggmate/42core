/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:14:39 by jotong            #+#    #+#             */
/*   Updated: 2025/07/20 00:01:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void check_update_element_ctr(t_pool *mem_p, t_map *map, char c)
{
	if (c == 'C')
		map->c += 1;
	else if (c == 'P')
		map->start += 1;
	else if (c == 'E')
		map->exit += 1;
	else if (!(c == '1' || c == '0'))
		free_and_exit(mem_p, &map->fd, 1);
	if (map->start > 1)
		free_end_exit(mem_p, &map->fd, 1);
	else if (map->exit > 1)
		free_end_exit(mem_p, &map->fd, 1);
}
