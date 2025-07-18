/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/18 22:58:01 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_opengl_20191021/mlx.h"

int	main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc != 2)
		return (1, write(2, "incorrect number of inputs!\n", 29));
	map = load_map(argv[1]);
	
	// create a window
	// load all required sprites
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
	return (0);
}
