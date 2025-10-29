#include "Zombie.hpp"

int	main(void)
{
	std::string n = "Hector";
	std::string n2 = "Hector2";
	Zombie* n_zombie = newZombie(n);
	delete n_zombie;

	randomChump(n2);
}