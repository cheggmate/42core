#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    // According to the subject, the program should take a parameter
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }

    // Manual test cases for different scalar types and pseudo-literals:
    
    std::cout << "--- Test 1: Char ---" << std::endl;
    ScalarConverter::convert("a"); 

    std::cout << "\n--- Test 2: Int ---" << std::endl;
    ScalarConverter::convert("42");

    std::cout << "\n--- Test 3: Float ---" << std::endl;
    ScalarConverter::convert("4.2f");

    std::cout << "\n--- Test 4: Double ---" << std::endl;
    ScalarConverter::convert("42.0");

    std::cout << "\n--- Test 5: Float Pseudo-literal ---" << std::endl;
    ScalarConverter::convert("-inff");

    std::cout << "\n--- Test 6: Double Pseudo-literal ---" << std::endl;
    ScalarConverter::convert("nan");

    std::cout << "\n--- Test 7: Non-displayable char ---" << std::endl;
    ScalarConverter::convert("0");

    return 0;
}