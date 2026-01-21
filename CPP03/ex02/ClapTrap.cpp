#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string c_name):
    _name(c_name),
    _attack_damage(0),
    _hit_points(10),
    _energy_points(10)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (this->_energy_points == 0 || this->_hit_points == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
                << " causing " << this->_attack_damage 
                << " points of damage !" << std::endl;
    this->_energy_points -= 1;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name << " took "
                << amount << " points of damage!"
                << std::endl;
    this->_hit_points -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (amount == 0)
    {
        std::cout << "Cannot call beRepaired with 0 points." << std::endl;
        return ;
    }
    if (this->_hit_points == 0 || this->_energy_points == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " repaired itself and gained " 
                << amount << " hit points!" << std::endl;
    this->_hit_points += amount;
}
