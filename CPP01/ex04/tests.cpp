/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:42:23 by jotong            #+#    #+#             */
/*   Updated: 2025/11/06 00:43:02 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include "sed_is_for_losers.hpp"

// static int	compare_file_happycase(std::string in_file, std::string ref_file)
// {
// 	std::string		file_generated = in_file + ".replace";
// 	std::ifstream	ifs1(file_generated);
// 	std::ifstream	ifs_ref(ref_file);
// 	std::string		line_ref;
// 	std::string		line1;
// 	if (!ifs_ref.is_open() || !ifs1.is_open())
// 		return 1;
	
// 	while (std::getline(ifs_ref, line_ref))
// 	{
// 		std::getline(ifs1, line1);
// 		if (std::strcmp(&line_ref[0], &line1[0]) != 0)
// 		{
// 			ifs_ref.close();
// 			ifs1.close();
// 			return 1;
// 		}	
// 	}
// 	ifs_ref.close();
// 	ifs1.close();
// 	return 0;
// }

// static int	compare_file_empty_replacement(std::string file_name,
// 			std::string s_search)
// {
// 	std::string		file_generated = file_name + ".replace";
// 	std::ifstream	ifs1(file_generated);
// 	std::ifstream	ifs_ref(file_name);
// 	std::string		line_ref;
// 	std::string		line1;
// 	if (!ifs_ref.is_open() || !ifs1.is_open())
// 		return 1;
// 	while (std::getline(ifs_ref, line_ref))
// 	{
// 		std::getline(ifs1, line1);
// 		size_t	pos = 0;
// 		while (line_ref.length() > 0
// 			&& (pos = line_ref.find(s_search, pos)) != std::string::npos)
// 		{
// 			line_ref.erase(pos, s_search.length());
// 		}
// 		if (std::strcmp(&line_ref[0], &line1[0]) != 0)
// 		{
// 			ifs_ref.close();
// 			ifs1.close();
// 			return 1;
// 		}
// 	}
// 	ifs_ref.close();
// 	ifs1.close();
// 	return 0;
// }

// static int	compare_empty_file(std::string file_name)
// {
// 	std::string		file_generated = file_name + ".replace";
// 	std::ifstream	ifs1(file_generated);
// 	std::ifstream	ifs_ref(file_name);
// 	std::string		line_ref;
// 	std::string		line1;
// 	if (!ifs_ref.is_open() || !ifs1.is_open())
// 		return 1;
// 	std::getline(ifs_ref, line_ref);
// 	std::getline(ifs1, line1);
// 	if (line_ref.empty() && line1.empty())
// 	{
// 		ifs_ref.close();
// 		ifs1.close();
// 		return 0;
// 	}	
// 	ifs_ref.close();
// 	ifs1.close();
// 	return 1;
// }

// static int	compare_file(std::string file_name)
// {
// 	std::string		file_generated = file_name + ".replace";
// 	std::ifstream	ifs1(file_generated);
// 	std::ifstream	ifs_ref(file_name);
// 	std::string		line_ref;
// 	std::string		line1;
// 	if (!ifs_ref.is_open() || !ifs1.is_open())
// 		return 1;
	
// 	while (std::getline(ifs_ref, line_ref))
// 	{
// 		std::getline(ifs1, line1);
// 		if (std::strcmp(&line_ref[0], &line1[0]) != 0)
// 		{
// 			ifs_ref.close();
// 			ifs1.close();
// 			return 1;
// 		}
			
// 	}
// 	ifs_ref.close();
// 	ifs1.close();
// 	return 0;
// }

// int main(void)
// {
// 	const char *prog_name = "./sed_is_for_losers";
// 	std::string test_file = "input_file.txt";
// 	std::ofstream ofs(test_file);
// 	ofs << "Fee Fi Fo Fum\nI smell the blood of an Englishman\nBe he alive, "
// 	<< "or be he dead\nI'll grind his bones to make my bread.\n1111" << std::endl;
// 	ofs.close();

// 	// --------- Unhappy scenarios ---------------
// 	// Too many parameters
// 	char	*av[] = {(char *)prog_name, (char *)"input_file.txt", (char *)"blood",
// 					(char *)"water", (char *)"extra_parameter"};
// 	int		ac = 5;
// 	if (sed_is_for_losers(ac, av) == 1)
// 		std::cout << "(Test 0) Too many params: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 0) Too many params: Failed.\n" << std::endl;
	
// 	// Too few parameters
// 	char	*av1[] = {(char *)prog_name, (char *)"input_file.txt",
// 						(char *)"blood"};
// 	int		ac1 = 3;
// 	if (sed_is_for_losers(ac1, av1) == 1)
// 		std::cout << "(Test 1) Too few params: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 1) Too few params: Failed.\n" << std::endl;
	
// 	// Incorrect file
// 	char 	*av2[] = {(char *)prog_name, (char *)"invalid_file1.txt",
// 						(char *)"blood", (char *)"water"};
// 	int		ac2 = 4;
// 	if (sed_is_for_losers(ac2, av2) == 1)
// 		std::cout << "(Test 2) Invalid file: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 2) Invalid file: Failed.\n" << std::endl;

// 	// Empty search param
// 	char 	*av3[] = {(char *)prog_name, (char *)"invalid_file.txt",
// 						(char *)"blood", (char *)"water"};
// 	int		ac3 = 4;
// 	if (sed_is_for_losers(ac3, av3) == 1)
// 		std::cout << "(Test 3) Empty search param: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 3) Empty search param: Failed.\n" << std::endl;
		
// 	// Empty file
// 	char 	*av4[] = {(char *)prog_name, (char *)"", (char *)"blood",
// 						(char *)"water"};
// 	int		ac4 = 4;
// 	if (sed_is_for_losers(ac4, av4) == 1)
// 		std::cout << "(Test 4) Empty file: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 4) Empty file: Failed.\n" << std::endl;
		
// 	// --------- Happy scenarios ---------------
// 	// Empty input file
// 	std::string test_file1 = "empty_file.txt";
// 	std::ofstream ofs2(test_file1);
// 	ofs2.close();
// 	char 	*av5[] = {(char *)prog_name, (char *)"empty_file.txt", (char *)"blood",
// 						(char *)"water"};
// 	int		ac5 = 4;
// 	if (sed_is_for_losers(ac5, av5) == 0 && compare_empty_file(test_file1) == 0)
// 		std::cout << "(Test 5) Empty input file: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 5) Empty input file: Failed.\n" << std::endl;
// 	std::remove("empty_file.txt.replace");
		
// 	// No matching character in input file matching search string
// 	char 	*av6[] = {(char *)prog_name, (char *)"input_file.txt", (char *)"bloody",
// 						(char *)"water"};
// 	int		ac6 = 4;
// 	if (sed_is_for_losers(ac6, av6) == 0 && compare_file(test_file) == 0)
// 		std::cout << "(Test 6) No matching char in file: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 6) No matching char in file: Failed.\n" << std::endl;
// 	std::remove("input_file.txt.replace");
		
// 	// Replacing search string with empty string
// 	char 	*av7[] = {(char *)prog_name, (char *)"input_file.txt", (char *)"blood",
// 						(char *)""};
// 	int		ac7 = 4;
// 	if (sed_is_for_losers(ac7, av7) == 0 && compare_file_empty_replacement(test_file, "blood") == 0)
// 		std::cout << "(Test 7) Empty replacement string: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 7) Empty replacement string: Failed.\n" << std::endl;
// 	std::remove("input_file.txt.replace");
	
// 	// Happy case scenario - alphabets
// 	std::string expected_test8 = "input_file.txt.replaceref";
// 	std::ofstream ofs8(expected_test8);
// 	ofs << "Fee Fi Fo Fum\nI smell the water of an Englishman\nBe he alive, "
// 	<< "or be he dead\nI'll grind his bones to make my bread.\n1111" << std::endl;
// 	ofs8.close();

// 	char 	*av8[] = {(char *)prog_name, (char *)"input_file.txt",
// 						(char *)"blood", (char *)"water"};
// 	int		ac8 = 4;
// 	if (sed_is_for_losers(ac8, av8) == 0 && compare_file_happycase(test_file, expected_test8) == 0)
// 		std::cout << "(Test 8) Replace alphabets: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 8) Replace alphabets: Failed.\n" << std::endl;
// 	std::remove("input_file.txt.replace");
// 	std::remove("input_file.txt.replaceref");

	
// 	// Happy case scenario - numbers
// 	std::string expected_test9 = "input_file.txt.replaceref1";
// 	std::ofstream ofs9(expected_test9);
// 	ofs << "Fee Fi Fo Fum\nI smell the blood of an Englishman\nBe he alive, "
// 	<< "or be he dead\nI'll grind his bones to make my bread.\n2222" << std::endl;
// 	ofs9.close();
	
// 	char 	*av9[] = {(char *)prog_name, (char *)"input_file.txt",
// 						(char *)"1", (char *)"2"};
// 	int		ac9 = 4;
// 	if (sed_is_for_losers(ac9, av9) == 0 && compare_file_happycase(test_file, expected_test9) == 0)
// 		std::cout << "(Test 9) Replace numbers: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 9) Replace numbers: Failed.\n" << std::endl;
// 	std::remove("input_file.txt.replace");
// 	std::remove("input_file.txt.replaceref1");

// 	// Happy case scenario - special chars
// 	std::string expected_test10 = "input_file.txt.replaceref2";
// 	std::ofstream ofs10(expected_test10);
// 	ofs << "Fee Fi Fo Fum\nI smell the blood of an Englishman\nBe he alive, "
// 	<< "or be he dead\nI@ll grind his bones to make my bread.\n1111" << std::endl;
// 	ofs10.close();
	
// 	char 	*av10[] = {(char *)prog_name, (char *)"input_file.txt",
// 						(char *)"'", (char *)"@"};
// 	int		ac10 = 4;
// 	if (sed_is_for_losers(ac10, av10) == 0 && compare_file_happycase(test_file, expected_test10) == 0)
// 		std::cout << "(Test 10) Replace special chars: Passed.\n" << std::endl;
// 	else
// 		std::cout << "(Test 10) Replace special chars: Failed.\n" << std::endl;
// 	std::remove("input_file.txt.replace");
// 	std::remove("input_file.txt.replaceref2");

// 	std::remove("input_file.txt");
// 	std::remove("empty_file.txt");
// };

