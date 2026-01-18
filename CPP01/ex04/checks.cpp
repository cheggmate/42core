#include "sed_is_for_losers.hpp"

int	param_check(int ac)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of parameters." << std::endl;
		return 1;
	}
	return 0;
}

int	filename_check(char **av)
{
	std::string fname = av[1];
	if (fname.empty() || fname.length() == 0)
	{
		std::cout << "No filename provided." << std::endl;
		return 1;
	}
	return 0;
}
