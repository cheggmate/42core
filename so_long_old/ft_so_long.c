/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:46:42 by jotong            #+#    #+#             */
/*   Updated: 2025/07/25 22:58:24 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#ifdef __APPLE__
# include "minilibx_opengl_20191021/mlx.h"
#elif __linux__
# include "minilibx-linux/mlx.h"
#endif

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		return (write(2, "Error\nincorrect number of inputs!\n", 34), 1);
	check_asset_list();
	load_map(argv[1], &game);
	mlx_loop(game->mlx);
	return (0);
}
