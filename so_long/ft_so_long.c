/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/22 23:59:55 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		return (write(2, "Error\nincorrect number of inputs!\n", 34), 1);
	check_asset_list();
	load_map(argv[1], &game);
	printf("map->w = %d\n", game->map->w);
	// create a window - DONE
	// load all required sprites - DONE
	// create the different hooks
	//	* key handler
	//	* mouse handler
	//	* close handler
	//	* loop (game loop)
	
	// draw background
	// draw walls
	// draw collectibles
	// draw person

	// checks
	// person in wall?
	// new position in map?
	

	// when to unlock exit?

	// other handlers:
	// 	* replace collectible with background once collected
	// 	* move player
	// 	* collectible counter
	mlx_loop(game);
	return (0);
}
