#include "Ice.hpp"

Ice::Ice() {
    std::cout << "Ice default constructor called" << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this); // Returns a new Ice instance 
}

void    Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}