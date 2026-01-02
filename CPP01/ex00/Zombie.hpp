/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:27:10 by jotong            #+#    #+#             */
/*   Updated: 2026/01/02 18:03:47 by jotong           ###   ########.fr       */
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
	private:
		std::string name;

	public:
		Zombie() :
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
		}
		~Zombie()
		{
			std::cout << this->name << " is destroyed." << std::endl;
			return ;
		};
};

Zombie* newZombie (std::string name);
void randomChump(std::string name);

#endif
