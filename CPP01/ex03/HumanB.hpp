#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon *weapon;
	public:
		HumanB(const std::string& name) :
			name(name),
			weapon(NULL)
		{};
		void setWeapon(Weapon& weapon)
		{
			this->weapon = &weapon;
			return ;
		}
		void attack()
		{
			std::cout << name << " attacks with their " << weapon->getType() << std::endl;
			return ;
		};
};


#endif