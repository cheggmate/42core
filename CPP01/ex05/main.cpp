/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:03:11 by jotong            #+#    #+#             */
/*   Updated: 2025/11/09 00:24:18 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string complaint;
	int	done = 0;
	
	while (done == 0)
	{
		std::cout << "Input a complaint level." << std::endl;
		std::getline(std::cin, complaint);
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting..." << std::endl;
			done = 1;
			break ;
		}
		if (std::strcmp(&complaint[0], "exit") == 0)
		{
			done = 1;
			break ;
		}
		harl.complain(complaint);
	}
	return 0;
}
