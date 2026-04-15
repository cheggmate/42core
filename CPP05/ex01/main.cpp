#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    // --- Test 1: Form Grade Validation ---
    std::cout << "--- Test 1: Form Grade Out of Bounds ---" << std::endl;
    try {
        Form high("Top Secret", 0, 50); // Grade 0 too high
    } catch (std::exception &e) {
        std::cout << "Caught expected Exception: " << e.what() << std::endl;
    }

    try {
        Form low("Useless Paper", 151, 150); // Grade 151 too low
    } catch (std::exception &e) {
        std::cout << "Caught expected Exception: " << e.what() << std::endl;
    }

    // --- Test 2: Successful Signing ---
    std::cout << "\n--- Test 2: Successful Signing ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 1);
        Form contract("Employment Contract", 25, 50);
        
        std::cout << contract << std::endl; // Check initial state (unsigned)
        boss.signForm(contract);            // Should print success message
        std::cout << contract << std::endl; // Check final state (signed)
    } catch (std::exception &e) {
        std::cerr << "Unexpected failure: " << e.what() << std::endl;
    }

    // --- Test 3: Failed Signing (Grade Too Low) ---
    std::cout << "\n--- Test 3: Failed Signing ---" << std::endl;
    try {
        Bureaucrat intern("The Intern", 150);
        Form goldenForm("Golden Ticket", 1, 1);
        
        std::cout << intern << std::endl;
        std::cout << goldenForm << std::endl;
        
        intern.signForm(goldenForm); // Should print failure message with reason
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception leak: " << e.what() << std::endl;
    }

    // --- Test 4: Re-signing a Form ---
    std::cout << "\n--- Test 4: Double Signing ---" << std::endl;
    try {
        Bureaucrat mid("Manager", 50);
        Form expense("Expense Report", 60, 60);
        
        mid.signForm(expense);
        mid.signForm(expense); // Optional logic: how does your form handle already signed?
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
