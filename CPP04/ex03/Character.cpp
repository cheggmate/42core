#include "Character.hpp"

Character::Character() {
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character& other) {
    std::cout << "Character copy constructor called" << std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

void    Character::equip(AMateria* m) {
    int i;

    i = 0;
    if (!m)
        return ;
    while (i < 4 && this->_slot[i] != NULL)
        i++;
    if (i == 4)
        return ;
    else
        this->_slot[i] = m;
    return ;  
}

void    Character::unequip(int idx) {
    if (idx <0 || idx >= 4)
        return ;
    if (this->_slot[idx] == NULL)
        return;
    else {
        std::cout << "found a AMateria of type " << this->_slot[idx]->type << " at slot " \
        >> idx << " .\nRemoving..." << std::endl;
        this->_slot[idx] = NULL;
        
    }

    return ;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
}
