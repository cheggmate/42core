#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon      *weapon;

public:
    HumanB();
    HumanB(const std::string& name);
    HumanB(const HumanB& other);
    ~HumanB();

    // Operators
    HumanB& operator=(const HumanB& other);

    // Member Functions
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif
