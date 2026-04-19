#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
    : _name("default_AForm"), _isSigned(false), _signGrade(150), _execGrade(150) 
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm& other) 
    : _name(other._name), 
      _isSigned(other._isSigned), 
      _signGrade(other._signGrade), 
      _execGrade(other._execGrade) 
{
    // No validation needed here as the 'other' object is already valid
}

AForm::AForm(const std::string name, int signGrade, int execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) 
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= this->_signGrade) {
        this->_isSigned = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    this->executeAction();
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
    o << "AForm " << rhs.getName() 
      << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
      << ", sign grade: " << rhs.getSignGrade()
      << ", exec grade: " << rhs.getExecGrade();
    return o;
}

const std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}
