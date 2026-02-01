#include "ICharacter.hpp"

// ICharacter::ICharacter() {
//     std::cout << "ICharacter default constructor called" << std::endl;
// }

// ICharacter::ICharacter(const ICharacter& other) {
//     std::cout << "ICharacter copy constructor called" << std::endl;
//     *this = other;
// }

// ICharacter& ICharacter::operator=(const ICharacter& other) {
//     std::cout << "ICharacter assignment operator called" << std::endl;
//     if (this != &other) {
//         // Copy members here
//     }
//     return *this;
// }

ICharacter::~ICharacter() {
    std::cout << "ICharacter destructor called" << std::endl;
}
