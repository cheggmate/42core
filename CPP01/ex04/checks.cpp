/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:19:08 by jotong            #+#    #+#             */
/*   Updated: 2025/11/05 18:26:46 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.hpp"

int	param_check(int ac)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of parameters." << std::endl;
		return 1;
	}
	return 0;
}

int	filename_check(char **av)
{
	if (std::strlen(av[1]) == 0)
	{
		std::cout << "No filename provided." << std::endl;
		return 1;
	}
	return 0;
}
