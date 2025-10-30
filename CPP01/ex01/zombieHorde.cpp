#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int	i;

	if (N <= 0)
		return nullptr;
	i = 0;
	Zombie* zbs = new Zombie[N];
	while (i < N)
	{
		std::string zb_name = name;
		zb_name += ('0' + i);
		zbs[i].setName(zb_name);
		i++;
	}
	i = 0;
	while (i < N)
	{
		zbs[i].announce();
		i++;
	}
	return zbs;
}
