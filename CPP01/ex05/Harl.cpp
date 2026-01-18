#include "Harl.hpp"

void Harl::complain(std::string level)
{
	bool found = false;
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	HarlMembers functions[] = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	size_t l_count = sizeof(levels) / sizeof(levels[0]);

	int len_level = level.length();
	for (int j = 0; j < len_level; j++)
	{
		level[j] = std::toupper(level[j]);
	}
	
	for (size_t i = 0; i < l_count; i++)
	{
		if (level == levels[i])
		{
			// std::cout << "detected a match." << std::endl;
			(this->*functions[i])();
			found = true;
			break ;
		}
	};
	if (!found)
	{
		std::cout << "Unknown input: "
			<< "The provided level does not match the supported levels."
			<< std::endl;
	}
	return ;
};
