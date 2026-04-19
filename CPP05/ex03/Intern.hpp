#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // Mandatory function 
        AForm* makeForm(std::string formName, std::string target);

    private:
        // Helper functions for cleaner implementation
        AForm* _createShrubbery(std::string target);
        AForm* _createRobotomy(std::string target);
        AForm* _createPresidential(std::string target);
};

#endif
