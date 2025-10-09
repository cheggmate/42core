/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 00:55:06 by jotong            #+#    #+#             */
/*   Updated: 2025/10/10 00:55:06 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string text;
	int			count;

	count = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (count < argc)
	{
		text = argv[count];
		for (char& c : text)
		c = std::toupper(c);
		std::cout << text;
		std::cout << " ";
		count++;
	}
	std::cout << std::endl;
	return 0;	
}