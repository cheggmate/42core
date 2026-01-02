/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_replace.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:02:28 by jotong            #+#    #+#             */
/*   Updated: 2026/01/02 20:48:20 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.hpp"

void	find_and_replace(std::string file_in, std::string to_find, std::string to_replace)
{
	std::string file_out = file_in + ".replace";
	std::ifstream ifs(file_in.c_str());
	std::ofstream ofs(file_out.c_str());
	std::string line;

	if (!ifs.is_open())
	{
		std::cout << "Could not open input file." << std::endl;
		return ;
	}
	if (!ofs.is_open())
	{
		std::cout << "Could not create putput file." << std::endl;
		ifs.close();
		return ;
	}
	while(std::getline(ifs, line))
	{
		while(line.find(to_find) != std::string::npos)
		{
			size_t pos = 0;
			while((pos = line.find(to_find, pos)) != std::string::npos)
			{
				ofs << line.substr(0, pos);
				ofs << to_replace;
				line = line.substr(pos + to_find.length());
				pos = 0;
			}
		}
		ofs << line << std::endl;
	}
	
	ifs.close();
	ofs.close();
	return ;
}
