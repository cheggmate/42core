/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:53:32 by jotong            #+#    #+#             */
/*   Updated: 2025/11/09 21:55:25 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl 		harl;
	std::string complaint;
	
	if (ac != 2)
	{
		std::cout << "Too many arguments." << std::endl;
		return 1;
	}
	complaint = av[1];
	harl.complain(complaint);
	return 0;
}
