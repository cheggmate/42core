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
