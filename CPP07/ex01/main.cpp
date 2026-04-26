#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const & x) {
    std::cout << x << " ";
}

void incrementInt(int & n) {
    n++;
}

int main() {
    // Test 1: Integer Array
    std::cout << "--- Integer Test ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;

    std::cout << "Original: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intLen, incrementInt);
    
    std::cout << "Incremented: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << "\n" << std::endl;

    std::cout << "--- String Test ---" << std::endl;
    std::string strArray[] = {"Hello", "42", "Taitung", "Chishang"};
    size_t strLen = 4;

    std::cout << "Words: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << "\n" << std::endl;


    // Test 3: Float Array
    std::cout << "--- Float Test ---" << std::endl;
    float floatArray[] = {42.42f, 21.21f, 0.0f};
    size_t floatLen = 3;

    std::cout << "Floats: ";
    iter(floatArray, floatLen, printElement<float>);
    std::cout << "\n" << std::endl;

    return 0;
}
