/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:41:57 by jotong            #+#    #+#             */
/*   Updated: 2025/11/02 23:58:00 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of parameters." << std::endl;
		return 1;
	}
	if (std::strlen(av[1]) == 0)
	{
		std::cout << "No filename provided." << std::endl;
		return 1;
	}
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Could not open file." << std::endl;
		return 1;
	}
	if (std::strlen(av[2]) == 0)
	{
		std::cout << "Invalid string to replace." << std::endl;
		return 1;
	}
	// std::string to_find = av[3];
	// if (to_find.find(av[2]) != std::string::npos)
	// {
	// 	std::cout << "Parameter to find cannot be in parameter to replace to avoid infinite loops." << std::endl;
	// 	return 1;
	// }
	inputFile.close();
	find_and_replace(av[1], av[2], av[3]);
	return 0;
}
