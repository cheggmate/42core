#include "Character.hpp"

Character::Character() {
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; i++) this->_slot[i] = NULL; // Must initialize! [cite: 241]
}

Character::Character(const Character& other) {
    std::cout << "Character copy constructor called" << std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; i++) {
            if (this->_slot[i]) delete this->_slot[i]; // Clean old [cite: 254]
            if (other._slot[i]) this->_slot[i] = other._slot[i]->clone();
            else this->_slot[i] = NULL;
        }
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

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !this->_slot[idx]) return;
    std::cout << "Removing " << this->_slot[idx]->getType() << " at " << idx << std::endl;
    this->_slot[idx] = NULL; // Do NOT delete the materia [cite: 243]
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::use(int idx, ICharacter& target) {
    // Check if the index is valid and if a Materia exists in that slot [cite: 242]
    if (idx >= 0 && idx < 4 && this->_slot[idx] != NULL) {
        this->_slot[idx]->use(target); // Calls Ice::use or Cure::use 
    }
    // If the slot is empty or the index is invalid, nothing happens [cite: 242]
}
