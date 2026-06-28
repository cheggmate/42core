#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <exception>
# include <string>
# include <sstream>

class RPN {
public:
    RPN();                             // Default Constructor
    RPN(const RPN& other);    // Copy Constructor
    RPN& operator=(const RPN& other); // Assignment Operator
    ~RPN();                            // Destructor
	void start_rpn(char **input);

	class ErrorInInputs : public std::exception {
    public:
        virtual const char* what() const throw();
    };
private: 
	std::stack<int> _stack;
};

#endif
