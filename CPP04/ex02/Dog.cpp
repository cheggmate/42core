#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
     this->b = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    b = new Brain(*other.b);
}

Dog& Dog::operator=(const Dog& other) {
    int i;

    i = 0;
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
        AAnimal::operator=(other);
        while (i < 100)
        {
            this->b->ideas[i] = other.b->ideas[i];
            i++;
        }
        
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->b;
}

void    Dog::makeSound() const {
    std::cout << "Dogs woof.." << std::endl;
}

Brain*  Dog::getBrain() {
    return this->b;
}

