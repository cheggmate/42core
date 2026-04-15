#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
    : _name("default_form"), _isSigned(false), _signGrade(150), _execGrade(150) 
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) 
{
    // Grade validation must happen inside the body after initialization
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= this->_signGrade) {
        this->_isSigned = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
    o << "Form " << rhs.getName() 
      << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
      << ", sign grade: " << rhs.getSignGrade()
      << ", exec grade: " << rhs.getExecGrade();
    return o;
}

const std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}
