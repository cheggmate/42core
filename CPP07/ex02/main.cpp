#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 5

int main() {
    std::cout << "--- 1. Basic Allocation ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    std::cout << "\n--- 2. Deep Copy Test ---" << std::endl;
    Array<int> copy(numbers);
    std::cout << "Changing original numbers[0] to 999..." << std::endl;
    numbers[0] = 999;
    
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0] (should still be 0): " << copy[0] << std::endl;

    std::cout << "\n--- 3. Assignment Test ---" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    std::cout << "Assigned[0]: " << assigned[0] << std::endl;

    std::cout << "\n--- 4. Complex Types (Strings) ---" << std::endl;
    Array<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "World";
    std::cout << strings[0] << " " << strings[1] << std::endl;

    std::cout << "\n--- 5. Const Correctness ---" << std::endl;
    const Array<int> constArr(numbers);
    std::cout << "Const access [2]: " << constArr[2] << std::endl;

    std::cout << "\n--- 6. Exception Test ---" << std::endl;
    try {
        std::cout << "Attempting to access index 10 in size 5 array..." << std::endl;
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to access index -1..." << std::endl;
        std::cout << numbers[-1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}
