/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:03:04 by jotong            #+#    #+#             */
/*   Updated: 2025/11/09 00:10:58 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	bool found = false;
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	HarlMembers functions[] = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	size_t l_count = sizeof(levels) / sizeof(levels[0]);

	int len_level = level.length();
	for (int j = 0; j < len_level; j++)
	{
		level[j] = std::toupper(level[j]);
	}
	
	for (size_t i = 0; i < l_count; i++)
	{
		if (level == levels[i])
		{
			std::cout << "detected a match." << std::endl;
			(this->*functions[i])();
			found = true;
			break ;
		}
	};
	if (!found)
	{
		std::cout << "Unknown level.\n"
			<< "The provided level does not match the supported levels."
			<< std::endl;
	}
	return ;
};
