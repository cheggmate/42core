#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string cname) : 
    ClapTrap(cname + "_clap_name"),
    ScavTrap(cname),
    FragTrap(cname),
    _name(cname)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
    
    std::cout << "DiamondTrap constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
        this->ClapTrap::_name = other.ClapTrap::_name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name: " << this->_name << " and "
                << "my ClapTrap name: " << ClapTrap::_name << std::endl;
}

// void    DiamondTrap::attack(const std::string& target){
//     if (this->_energy_points == 0 || this->_hit_points == 0)
//     {
//         std::cout << "ScavTrap " << this->_name << " has no energy points left!" << std::endl;
//         return ;
//     }
//     std::cout << "ScavTrap " << this->_name << " attacks " << target 
//                 << " causing " << this->_attack_damage 
//                 << " points of damage !" << std::endl;
//     this->_energy_points -= 1;
// }
