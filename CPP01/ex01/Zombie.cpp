#include "Zombie.hpp"

Zombie* newZombie (std::string n)
{
	Zombie* z =  new Zombie();
	z->setName(n);
	return z;
}
