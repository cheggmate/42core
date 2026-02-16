#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();                             // Default Constructor
    Dog(const Dog& other);    // Copy Constructor
    Dog& operator=(const Dog& other); // Assignment Operator
    ~Dog();                            // Destructor
    void    makeSound() const;
    Brain*  getBrain();

private:
    Brain*  b;
};

#endif
