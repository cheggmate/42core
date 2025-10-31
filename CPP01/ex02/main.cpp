/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:51:28 by jotong            #+#    #+#             */
/*   Updated: 2025/10/31 20:51:29 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string		variable = "HI THIS IS BRAIN";
	std::string*	stringPtr = &variable;
	std::string&	stringRef = variable;

	std::cout << "variable = " << &variable << std::endl;
	std::cout << "stringPtr = " << &stringPtr << std::endl;
	std::cout << "stringRef = " << &stringRef << std::endl;

	std::cout << "variable = " << variable << std::endl;
	std::cout << "stringPtr = " << *stringPtr << std::endl;
	std::cout << "stringRef = " << stringRef << std::endl;
	return 0;
}
