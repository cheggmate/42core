#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException& 
Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& src) throw() {
    if (this != &src) {
        (void)src; // Exceptions in this module usually have no data to copy
    }
    return *this;
}

Bureaucrat::GradeTooHighException& 
Bureaucrat::GradeTooHighException::throw() {
}

Bureaucrat::GradeTooHighException& 
Bureaucrat::GradeTooHighException::throw(const GradeTooHighException& src) {
    *this = src;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

Bureaucrat::GradeTooHighException& 
Bureaucrat::~GradeTooHighException()::throw() {
}

Bureaucrat::GradeTooLowException& 
Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException& src) throw() {
    if (this != &src) {
        (void)src; // Exceptions in this module usually have no data to copy
    }
    return *this;
}

Bureaucrat::GradeTooLowException& 
Bureaucrat::GradeTooLowException::throw() {
}

Bureaucrat::GradeTooLowException& 
Bureaucrat::GradeTooLowException::throw(const GradeTooLowException& src) {
    *this = src;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

Bureaucrat::GradeTooLowException& 
Bureaucrat::~GradeTooLowException()::throw() {
}

std::string	Bureaucrat::getName() {
	return this.name;
}

int	Bureaucrat::getGrade() {
	return this.grade;
}

class Bureaucrat::GradeTooHighException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Grade is too high! (Limit is 1)";
	}
};

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

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}
