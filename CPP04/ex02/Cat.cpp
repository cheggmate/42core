#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->b = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    b = new Brain(*other.b);
}

Cat& Cat::operator=(const Cat& other) {
    int i;

    i = 0;
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
        Animal::operator=(other);
        while (i < 100)
        {
            this->b->ideas[i] = other.b->ideas[i];
            i++;
        }
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->b;
}

void    Cat::makeSound() const {
    std::cout << "Cats meow.." << std::endl;
}

Brain*  Cat::getBrain() {
    return this->b;
}
