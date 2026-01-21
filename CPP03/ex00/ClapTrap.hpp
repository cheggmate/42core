#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
public:
    ClapTrap(std::string cname);		// Default Constructor
    ClapTrap(const ClapTrap& other);	// Copy Constructor
    ClapTrap& operator=(const ClapTrap& other);		// Assignment Operator
    ~ClapTrap();                            // Destructor
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

private:
   std::string _name;
	unsigned int         _attack_damage;
	unsigned int         _hit_points;
   unsigned int         _energy_points;
};

#endif
