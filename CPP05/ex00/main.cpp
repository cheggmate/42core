#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
    // --- Test 1: Standard Construction and Insertion Operator ---
    std::cout << "--- Test 1: Basic Initialization ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        std::cout << bob << std::endl; // Should print: Bob, bureaucrat grade 1. 
    } catch (std::exception &e) {
        std::cerr << "Unexpected failure: " << e.what() << std::endl;
    }

    // --- Test 2: Grade Too High at Construction ---
    std::cout << "\n--- Test 2: Grade Too High (0) ---" << std::endl;
    try {
        Bureaucrat tooHigh("Icarus", 0); 
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // --- Test 3: Grade Too Low at Construction ---
    std::cout << "\n--- Test 3: Grade Too Low (151) ---" << std::endl;
    try {
        Bureaucrat tooLow("Slacker", 151);
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // --- Test 4: Successful Grade Increment/Decrement ---
    std::cout << "\n--- Test 4: Increment and Decrement ---" << std::endl;
    try {
        Bureaucrat jo("Jo", 100);
        std::cout << "Before: " << jo << std::endl;
        
        jo.incrementGrade(); // Should become 99 
        std::cout << "After Increment: " << jo << std::endl;
        
        jo.decrementGrade(); // Should become 100
        std::cout << "After Decrement: " << jo << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // --- Test 5: Exception on Increment (at grade 1) ---
    std::cout << "\n--- Test 5: Incrementing Grade 1 ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 1);
        boss.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // --- Test 6: Exception on Decrement (at grade 150) ---
    std::cout << "\n--- Test 6: Decrementing Grade 150 ---" << std::endl;
    try {
        Bureaucrat intern("The Intern", 150);
        intern.decrementGrade();
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}