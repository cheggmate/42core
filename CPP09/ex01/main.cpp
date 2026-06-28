#include "RPN.hpp"

bool validate_chars(char **argv) {
	std::stringstream	ss(argv[1]);
	std::string			token;
	while (ss >> token) {
		if (token.length() != 1) {
			std::cerr << "Error! invalid chars / expected spaces between inputs but none found." << std::endl;
            return false;
        }
	}
	char c = token[0];
	if (!(std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/')) {
		std::cerr << "Error! invalid chars found." << std::endl;
		return false;
	} 
	return true;
}

int main(int argc, char **argv) {
	if (argc == 1)
		return 1;
	
	if (!validate_chars(argv)) {
		return 1;
	}
		
	RPN	rpn;
	rpn.start_rpn(argv);
	return 0;
}