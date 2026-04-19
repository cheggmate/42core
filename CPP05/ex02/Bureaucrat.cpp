#include "Bureaucrat.hpp"

std::string	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade = grade;
}

void	Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } catch (std::exception & e) {
        std::cerr << this->_name << " could not execute " << form.getName() 
                  << " because: " << e.what() << std::endl;
    }
}

void	Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade++;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}
std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    
    // 4. Return the stream
    return o;
}


Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::signForm(AForm & form) {
    try {
        form.beSigned(*this);
        
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } 
    catch (const std::exception & e) {
        // Failure message: <bureaucrat> couldn't sign <form> because <reason>.
        std::cout << this->_name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << "." << std::endl;
    }
}
