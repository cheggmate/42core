/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 00:55:06 by jotong            #+#    #+#             */
/*   Updated: 2025/10/12 17:03:49 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string text;
	size_t		i;
	int			count;

	count = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (count < argc)
	{
		i = 0;
		text = argv[count];
		while (i < text.length())
		{
			text[i] = std::toupper(text[i]);
			i++;
		}
		std::cout << text;
		std::cout << " ";
		count++;
	}
	std::cout << std::endl;
	return 0;	
}
