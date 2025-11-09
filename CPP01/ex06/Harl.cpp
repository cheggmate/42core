/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:53:43 by jotong            #+#    #+#             */
/*   Updated: 2025/11/09 22:34:28 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	bool		found = false;
	int			len_level = level.length();
	int			result = -1;
	std::string	levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	size_t		l_count = sizeof(levels) / sizeof(levels[0]);
	HarlMembers functions[] = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	for (int j = 0; j < len_level; j++)
	{
		level[j] = std::toupper(level[j]);
	}
	
	for (size_t i = 0; i < l_count; i++)
	{
		if (level == levels[i])
		{
			result = i;
			found = true;
			break;
		}
	};
	if (!found)
	{
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
		return ;
	}
		
	switch (result) {
		case 0 : // Debug
			(this->*functions[0])();
			std::cout << "\n" << std::endl;
		case 1 : // Info
			(this->*functions[1])();
			std::cout << "\n" << std::endl;
		case 2 : // Warning
			(this->*functions[2])();
			std::cout << "\n" << std::endl;
		case 3 : // Error
			(this->*functions[3])();
			std::cout << "\n" << std::endl;
	}
	
	return ;
}
