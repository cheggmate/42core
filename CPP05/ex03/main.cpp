#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm* rrf;

    std::cout << "--- TEST 1: Robotomy Request ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // Important: prevent memory leaks
    }

    std::cout << "\n--- TEST 2: Shrubbery Creation ---" << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- TEST 3: Presidential Pardon ---" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- TEST 4: Unknown Form ---" << std::endl;
    // This should print an error message and return NULL
    rrf = someRandomIntern.makeForm("world domination", "Earth");
    if (rrf) {
        boss.signForm(*rrf);
        delete rrf;
    } else {
        std::cout << "Intern failed to create the form as expected." << std::endl;
    }

    return 0;
}
