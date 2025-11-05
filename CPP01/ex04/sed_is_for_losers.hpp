#ifndef SED_IS_FOR_LOSERS_HPP
# define SED_IS_FOR_LOSERS_HPP

# include <fstream>
# include <iostream>
# include <string>

int		filename_check(char **av);
void	find_and_replace(std::string file_in, std::string to_find, std::string to_replace);
int		input_filecheck(std::ifstream inputFile);
int		param_check(int ac);
int		sed_is_for_losers(int ac, char **av);

#endif