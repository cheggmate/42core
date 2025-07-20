/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/20 16:00:25 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc != 2)
		return (write(2, "incorrect number of inputs!\n", 29), 1);
	map = load_map(argv[1]);
	ft_printf("map wdith: %d\n", map->w);
	
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
