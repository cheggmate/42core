#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib> // For std::rand()

class RobotomyRequestForm : public AForm {
    public:
        // Orthodox Canonical Form 
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();

        // Concrete implementation of the execution action 
        virtual void executeAction() const;

    private:
        const std::string _target;
        // Grade requirements: sign 72, exec 45 
        RobotomyRequestForm(); // Hidden default constructor
};

#endif