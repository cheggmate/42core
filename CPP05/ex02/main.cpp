#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // Seed for Robotomy's 50% success chance
    std::srand(std::time(NULL));

    // --- 1. ShrubberyCreationForm Test (Sign 145, Exec 137) ---
    std::cout << "--- TEST: Shrubbery Creation ---" << std::endl;
    try {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrub("backyard");
        
        std::cout << shrub << std::endl;
        gardener.signForm(shrub);
        gardener.executeForm(shrub); // Should create backyard_shrubbery file
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- 2. RobotomyRequestForm Test (Sign 72, Exec 45) ---
    std::cout << "\n--- TEST: Robotomy Request ---" << std::endl;
    try {
        Bureaucrat scientist("Scientist", 40);
        RobotomyRequestForm robot("Bender");
        
        scientist.signForm(robot);
        scientist.executeForm(robot); // Drilling noises + 50% success/fail
        scientist.executeForm(robot); // Run again to see randomness
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- 3. PresidentialPardonForm Test (Sign 25, Exec 5) ---
    std::cout << "\n--- TEST: Presidential Pardon ---" << std::endl;
    try {
        Bureaucrat president("President", 3);
        PresidentialPardonForm pardon("Arthur Dent");
        
        president.signForm(pardon);
        president.executeForm(pardon); // Should announce the pardon
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- 4. Failure: Unsigned Form ---
    std::cout << "\n--- TEST: Execute Unsigned Form ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 1);
        PresidentialPardonForm unsignedPardon("Zaphod");
        
        boss.executeForm(unsignedPardon); // Should fail because not signed
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- 5. Failure: Grade Too Low for Execution ---
    std::cout << "\n--- TEST: Grade Too Low to Execute ---" << std::endl;
    try {
        Bureaucrat midLevel("Middle Manager", 20);
        PresidentialPardonForm pardon("Poor Soul");
        
        midLevel.signForm(pardon); // Sign 25 (Success)
        midLevel.executeForm(pardon); // Exec 5 (Should fail)
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
