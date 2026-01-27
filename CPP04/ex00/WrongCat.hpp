#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();                             // Default Constructor
    WrongCat(const WrongCat& other);    // Copy Constructor
    WrongCat& operator=(const WrongCat& other); // Assignment Operator
    ~WrongCat();                            // Destructor
    void    makeSound() const;

private:
};

#endif
