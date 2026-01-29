#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
public:
    Brain();                             // Default Constructor
    Brain(const Brain& other);    // Copy Constructor
    Brain& operator=(const Brain& other); // Assignment Operator
    ~Brain();                            // Destructor
	std::string   ideas[100];

private:
};

#endif
