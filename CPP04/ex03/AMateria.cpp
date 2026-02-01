#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}
