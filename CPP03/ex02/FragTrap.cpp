#include "FragTrap.hpp"

FragTrap::FragTrap(std::string cname) : ClapTrap(cname) {
    this->_attack_damage = 30;
    this->_hit_points = 100;
    this->_energy_points = 100;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << other._name << " copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " sends a high five!" << std::endl;
}

void    FragTrap:: attack(const std::string& target) {
    if (this->_energy_points == 0 || this->_hit_points == 0)
    {
        std::cout << "FragTrap " << this->_name << " has no energy points left!" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << target 
                << " causing " << this->_attack_damage 
                << " points of damage !" << std::endl;
    this->_energy_points -= 1;
}
