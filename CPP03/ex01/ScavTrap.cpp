#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string cname) : ClapTrap(cname) {
    this->_attack_damage = 20;
    this->_hit_points = 100;
    this->_energy_points = 50;
    std::cout << "ScavTrap default constructor called for " << cname << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap "<< other._name << " copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    // std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
     std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate Keeper mode." << std::endl;
}

void    ScavTrap:: attack(const std::string& target) {
    if (this->_energy_points == 0 || this->_hit_points == 0)
    {
        std::cout << "ScavTrap " << this->_name << " has no energy points left!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target 
                << " causing " << this->_attack_damage 
                << " points of damage !" << std::endl;
    this->_energy_points -= 1;
}
