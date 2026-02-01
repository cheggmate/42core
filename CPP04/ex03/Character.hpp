#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
public:
    Character();                             // Default Constructor
    Character(const Character& other);    // Copy Constructor
    Character& operator=(const Character& other); // Assignment Operator
    ~Character();                            // Destructor

    // virtual ~ICharacter() {}
	std::string const & getName() const;
	void equip(AMateria* m);;
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
    std::string _name;
    AMateria*   _slot[4];
};

#endif
