#include "Animal.hpp"

Animal::Animal() :
    type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound() const {
    std::cout << "Animal says beep.." << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
