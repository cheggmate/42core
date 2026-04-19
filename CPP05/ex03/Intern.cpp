#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

// Helper methods to satisfy the "no messy if/else" rule
AForm* Intern::_createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }
AForm* Intern::_createRobotomy(std::string target) { return new RobotomyRequestForm(target); }
AForm* Intern::_createPresidential(std::string target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(std::string formName, std::string target) {
    // Array of names to match against
    std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of member function pointers to avoid excessive if/else 
    AForm* (Intern::*creators[])(std::string) = {
        &Intern::_createShrubbery,
        &Intern::_createRobotomy,
        &Intern::_createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    std::cout << "Error: Intern cannot create '" << formName << "' because it doesn't exist." << std::endl;
    return NULL;
}