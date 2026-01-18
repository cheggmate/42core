#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) 
    : _weapon(weapon), _name(name) {}

HumanA::HumanA(const HumanA& other) 
    : _weapon(other._weapon), _name(other._name) {}

HumanA& HumanA::operator=(const HumanA& other) {
    if (this != &other) {
        this->_name = other._name;
    }
    return *this;
}

HumanA::~HumanA() {}

void HumanA::attack() const {
    std::cout << _name << " attacks with " << _weapon.getType() << std::endl;
}
