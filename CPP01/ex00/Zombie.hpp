/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:27:10 by jotong            #+#    #+#             */
/*   Updated: 2025/10/29 20:53:43 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		{}
		void announce (void)
		{
			std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
			return ;
		};

		void setName(std::string n)
		{
			name = n;
		}
};

Zombie* newZombie (std::string name);
void randomChump(std::string name);