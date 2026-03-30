#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
        public:
            GradeTooHighException() throw() {}
            GradeTooHighException(const GradeTooHighException& src) throw() { *this = src; }
            GradeTooHighException& operator=(const GradeTooHighException& src) throw() { (void)src; return *this; }
            virtual ~GradeTooHighException() throw() {}

            virtual const char* what() const throw() {
                return "Grade is too high!";
            }
    };
    class GradeTooLowException : public std::exception {
        public:
            GradeTooHighException() throw();
            GradeTooHighException(const GradeTooLowException& src) throw();
            GradeTooHighException& operator=(const GradeTooLowException& src) throw()
            virtual ~GradeTooLowException() throw();

            virtual const char* what() const throw();
    };
    Bureaucrat(std::string name, int grade);                             // Default Constructor
    Bureaucrat(const Bureaucrat& other);    // Copy Constructor
    Bureaucrat& operator=(const Bureaucrat& other); // Assignment Operator
    ~Bureaucrat();                            // Destructor
    std::string getName();
    int         getGrade();
    void        incrementGrade();
    void        decrementGrade();


private:
    const std::string   _name;
    int                 _grade;
};

#endif
