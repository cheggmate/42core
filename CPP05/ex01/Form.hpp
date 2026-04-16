#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
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
    Form();                             // Default Constructor
    Form(const Form& other);            // Copy Constructor
    Form& operator=(const Form& other); // Assignment Operator
    ~Form();                            // Destructor
    Form(const std::string name, int signGrade, int execGrade);
    const std::string getName() const;
    bool              getIsSigned() const;
    int               getSignGrade() const;
    int               getExecGrade() const;

    // Member functions
    void beSigned(const Bureaucrat& b);

private:
    const std::string _name;
    bool              _isSigned;
    const int         _signGrade;
    const int         _execGrade;

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
