#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(std::string cname);                             // Default Constructor
    DiamondTrap(const DiamondTrap& other);    // Copy Constructor
    DiamondTrap& operator=(const DiamondTrap& other); // Assignment Operator
    ~DiamondTrap();                            // Destructor
	void	whoAmI();
	using ScavTrap::attack;

private:
    std::string	_name;
};

#endif
