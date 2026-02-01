#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria {
    protected:
        std::string type; // Ensure this is the name you use in .cpp
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);            // Add for Canonical Form
        AMateria& operator=(const AMateria& other); // Add for Canonical Form
        virtual ~AMateria();                        // MUST BE VIRTUAL [cite: 185]
        std::string const & getType() const;        // Ensure 'const' is here
        virtual AMateria* clone() const = 0;        // Ensure 'const' is here
        virtual void use(ICharacter& target);
};

#endif