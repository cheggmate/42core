#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
public:
    Cure();                             // Default Constructor
    Cure(const Cure& other);    // Copy Constructor
    Cure& operator=(const Cure& other); // Assignment Operator
    ~Cure();                            // Destructor
    Cure* clone() const = 0;
    void use(ICharacter& target);

private:
};

#endif
