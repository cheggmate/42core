#include "Cure.hpp"

Cure::Cure() : AMateria() {
    std::cout << "Cure default constructor called" << std::endl;
    this->type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}