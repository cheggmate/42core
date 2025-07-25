/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asset_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:22:26 by jotong            #+#    #+#             */
/*   Updated: 2025/07/25 22:13:16 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#ifdef __APPLE__
# include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "minilibx-linux/mlx.h"
#endif

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
	if (check_asset_exist("assets/candlelight1.xpm") == -1)
	{
		write(2, "Error\nCandle1 sprite not found.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (check_asset_exist("assets/candlelight2.xpm") == -1)
	{
		write(2, "Error\nCandle2 sprite not found.\n", 31);
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
