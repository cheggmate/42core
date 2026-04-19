#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
public:
    // Exception classes
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form grade is too high!"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form grade is too low!"; }
    };
    AForm();                             // Default Constructor
    AForm(const AForm& other);            // Copy Constructor
    AForm& operator=(const AForm& other); // Assignment Operator
    virtual ~AForm();                     // Destructor
    AForm(const std::string name, int signGrade, int execGrade);
    const std::string getName() const;
    bool              getIsSigned() const;
    int               getSignGrade() const;
    int               getExecGrade() const;
    void beSigned(const Bureaucrat& b);
    void execute(Bureaucrat const & executor) const;
protected:
    virtual void executeAction() const = 0;
private:
    const std::string _name;
    bool              _isSigned;
    const int         _signGrade;
    const int         _execGrade;

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif
