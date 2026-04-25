#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

static bool checkChar(std::string str, char c) {
    if (str.find(c) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

static void print_types(const std::string& literal, std::string type) {
    // 1. Handle Pseudo-literals and non-sensical inputs immediately
    if (type == "pseudo" || literal == "nan" || literal == "nanf" || 
        literal == "inf" || literal == "+inf" || literal == "-inf" ||
        literal == "inff" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        
        if (literal.find("nan") != std::string::npos) {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else {
            std::string sign = (literal[0] == '-') ? "-" : "+";
            std::cout << "float: " << sign << "inff" << std::endl;
            std::cout << "double: " << sign << "inf" << std::endl;
        }
        return;
    }

    // 2. For all valid numeric types, convert to double to simplify casting
    double d;
    if (type == "char")
        d = static_cast<double>(literal[0]);
    else
        d = atof(literal.c_str());

    // 3. Output Char (Handling non-displayable vs impossible)
    std::cout << "char: ";
    if (d < 0 || d > 127 || std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    } else if (d < 32 || d > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    // 4. Output Int (Handling overflow)
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }

    // 5. Output Float and Double with .0 precision 
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	std::string	type;
	size_t 		i;
	int			has_decimal;

	i = 0;
	has_decimal = 0;
	if (literal == "nan" || literal == "nanf" || 
        literal == "inf" || literal == "+inf" || literal == "-inf" ||
        literal == "inff" || literal == "+inff" || literal == "-inff") {
        print_types(literal, "pseudo");
        return;
    }
    if (literal.length() == 1 && literal[0] >= 'a' && literal[0] <= 'z')
		type = "char";
	else if (literal[0] == '+' || literal[0] == '-' || (literal[0] >= '0' && literal[0] <= '9'))
	{
		while (i < literal.length())
		{
			if (literal[i] >= '0' && literal[i] <= '9') {

			}
			else if (literal[i] == '.')
				has_decimal = 1;
			else
				break;
			i++;
		}
		
		if (i == literal.length())
		{
			if (has_decimal == 0)
				type = "int";
			else if (has_decimal == 1)
				type = "double";
		}
		else if (i == literal.length() - 1)
		{
			if (literal.length() >= 3 && has_decimal == 1 && literal[literal.length() - 1] == 'f')
				type = "float";
		}
	}
	else if (checkChar(literal, '/')) {
		std::cout << "Invalid input received." << std::endl;
		return ;
	}
	print_types(literal, type);
}
