#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

// AMateria& AMateria::operator=(const AMateria& other) {
//     std::cout << "AMateria assignment operator called" << std::endl;
//     if (this != &other) {
//         // Copy members here
//         this->_type = other._type;
//     }
//     return *this;
// }

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() {
    return (this->type);
}

void AMateria::use(ICharacter& target) {
    (void)target; // Default does nothing, overridden by Ice/Cure [cite: 225-227]
}
