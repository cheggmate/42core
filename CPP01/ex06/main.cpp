#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl 		harl;
	std::string complaint;
	
	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	complaint = av[1];
	harl.complain(complaint);
	return 0;
}
