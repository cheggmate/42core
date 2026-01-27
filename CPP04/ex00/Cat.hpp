#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal{
public:
    Cat();                             // Default Constructor
    Cat(const Cat& other);    // Copy Constructor
    Cat& operator=(const Cat& other); // Assignment Operator
    ~Cat();                            // Destructor
    void    makeSound() const;

private:
};

#endif
