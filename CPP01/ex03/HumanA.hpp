#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
    private:
        Weapon&     _weapon;
        std::string _name;

    public:
        HumanA(const std::string& name, Weapon& weapon);
        HumanA(const HumanA& other);
        HumanA& operator=(const HumanA& other);
        ~HumanA();

        // Member functions
        void attack() const;
};

#endif
