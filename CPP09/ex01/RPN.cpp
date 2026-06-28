#include "RPN.hpp"

const char* RPN::ErrorInInputs::what() const throw() {
    return "Error: invalid inputs.";
}

RPN::RPN() {
    // std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN& other) {
    // std::cout << "RPN copy constructor called" << std::endl;
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    // std::cout << "RPN assignment operator called" << std::endl;
    if (this != &other) {
		this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {
    // std::cout << "RPN destructor called" << std::endl;
}

void	RPN::start_rpn(char **input) {
    std::stringstream ss(input[1]);
    std::string token;

    while (ss >> token) {
        char c = token[0];

        // single digit
        if (std::isdigit(c)) {
            this->_stack.push(c - '0'); 
        } 
        // valid operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (this->_stack.size() < 2) {
                std::cerr << "Erro: Stack has insufficient params for operation." << std::endl;
                return;
            }

            int secondOperand = this->_stack.top(); 
			this->_stack.pop();
            int firstOperand = this->_stack.top(); 
			this->_stack.pop();

            if (c == '+')
				this->_stack.push(firstOperand + secondOperand);
            else if (c == '-')
				this->_stack.push(firstOperand - secondOperand);
            else if (c == '*')
				this->_stack.push(firstOperand * secondOperand);
            else if (c == '/') {
                if (secondOperand == 0) { // Protect against division by zero
                    std::cerr << "Error: Division by zero failed." << std::endl;
                    return;
                }
                this->_stack.push(firstOperand / secondOperand);
            }
        }
    }

    // After parsing everything, exactly one final result must remain on the stack
    if (this->_stack.size() != 1) {
        std::cerr << "Error: Final stack has more than one element" << std::endl; // Output to standard error
        return;
    }

    // Success! Print the final result to standard output
    std::cout << this->_stack.top() << std::endl;
}


