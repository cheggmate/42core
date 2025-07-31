/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asset_checks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:22:26 by jotong            #+#    #+#             */
/*   Updated: 2025/07/27 17:27:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#ifdef __APPLE__
# include "../minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "../minilibx-linux/mlx.h"
#endif

void	check_asset_ani(void)
{
	if (check_asset_exist("assets/lightning1.xpm") == -1)
	{
		write(2, "Error\nLightning sprite not found.\n", 35);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/lightning2.xpm") == -1)
	{
		write(2, "Error\nLightning2 sprite not found.\n", 35);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/lightning3.xpm") == -1)
	{
		write(2, "Error\nLightning3 sprite not found.\n", 35);
		exit(EXIT_FAILURE);
	}
}

void	check_asset_list2(void)
{
	if (check_asset_exist("assets/player_door_c.xpm") == -1)
	{
		write(2, "Error\nPlayer sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/player_door_o.xpm") == -1)
	{
		write(2, "Error\nPlayer sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/enemy.xpm") == -1)
	{
		write(2, "Error\nEnemy sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
}

void	check_asset_list(void)
{
	if (check_asset_exist("assets/player.xpm") == -1)
	{
		write(2, "Error\nPlayer sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/wall.xpm") == -1)
	{
		write(2, "Error\nWall sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/door.xpm") == -1)
	{
		write(2, "Error\nExit sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/collectible.xpm") == -1)
	{
		write(2, "Error\nCollectible sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/floor.xpm") == -1)
	{
		write(2, "Error\nFloor sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
}
