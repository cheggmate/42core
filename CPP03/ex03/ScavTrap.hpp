#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap(std::string c_name);                             // Default Constructor
    ScavTrap(const ScavTrap& other);    // Copy Constructor
    ScavTrap& operator=(const ScavTrap& other); // Assignment Operator
    ~ScavTrap();                            // Destructor
    void    guardGate();
	void    attack(const std::string& target);

private:
};

#endif
