#include "RobotomyRequestForm.hpp"

// Initialize with required grades: sign 72, exec 45 [cite: 198]
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void)other; // Base class handles assignment of isSigned
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
    // 1. Make drilling noises
    std::cout << "* VRRRRRRR... DRILL NOISES... VRRRRRRR *" << std::endl;

    // 2. 50% success logic
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    }
}
