#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap(std::string cname);                             // Default Constructor
    FragTrap(const FragTrap& other);    // Copy Constructor
    FragTrap& operator=(const FragTrap& other); // Assignment Operator
    ~FragTrap();                            // Destructor
    void	highFivesGuys(void);
	void    attack(const std::string& target);

private:
};

#endif
