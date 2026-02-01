#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria  {
public:
    Ice();                             // Default Constructor
    Ice(const Ice& other);    // Copy Constructor
    Ice& operator=(const Ice& other); // Assignment Operator
    ~Ice();                            // Destructor
    void use(ICharacter& target);
    // Both need to match the base class exactly
    AMateria* clone() const;

// private:
};

#endif
