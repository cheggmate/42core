#include "HumanB.hpp"

HumanB::HumanB() : name("Default"), weapon(NULL) {}

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

HumanB::HumanB(const HumanB& other) : name(other.name), weapon(other.weapon) 
{
    // The body is empty because the work is already done 
    // in the initialization list above
}

HumanB& HumanB::operator=(const HumanB& other) 
{
    if (this != &other) {
        this->name = other.name;
        this->weapon = other.weapon;
    }
    return *this;
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() {
    if (this->weapon)
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}