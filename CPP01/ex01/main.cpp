#include "Zombie.hpp"

int main(void)
{
	std::string name = "Howard";
	int	const	N = 10;
	Zombie*		zb;

	zb = zombieHorde(N, name);
	if (zb != nullptr)
	{
		delete[] zb;
	}
	return 0;
}
