#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    int i;
    
    i = 0;
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
        while (i < 100)
        {
            ideas[i] = other.ideas[i];
            i++;
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}
