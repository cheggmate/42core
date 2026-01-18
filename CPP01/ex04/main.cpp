#include "sed_is_for_losers.hpp"

int	sed_is_for_losers(int ac, char **av)
{
	if (param_check(ac) == 1)
		return 1;
	if (filename_check(av) == 1)
		return 1;
	
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Could not open file."
		<< "Check if the file exists or the right permissions are set." << std::endl;
		return 1;
	}
	std::string line = av[2];
	if (line.empty() || line.length() == 0)
	{
		std::cout << "Invalid string to replace." << std::endl;
		return 1;
	}
	inputFile.close();
	find_and_replace(av[1], av[2], av[3]);
	return 0;
}

int main(int ac, char **av)
{
	return(sed_is_for_losers(ac, av));
}
