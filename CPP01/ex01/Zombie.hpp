/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:38:07 by jotong            #+#    #+#             */
/*   Updated: 2025/10/31 00:24:05 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cctype>

class Zombie
{
	private :
		std::string name;

	public :
		Zombie () :
			name("")
		{};
		void announce (void)
		{
			std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
			return ;
		};
		void setName(std::string n)
		{
			name = n;
		};
};

Zombie* newZombie (std::string n);
Zombie* zombieHorde(int N, std::string name);
#endif
