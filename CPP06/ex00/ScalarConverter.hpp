#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cmath>
# include <limits>

class ScalarConverter {
private:
    ScalarConverter();                             // Default Constructor
    ScalarConverter(const ScalarConverter& other);    // Copy Constructor
    ScalarConverter& operator=(const ScalarConverter& other); // Assignment Operator
    ~ScalarConverter();                            // Destructor

public:
    static void convert(const std::string& literal);
};

#endif
