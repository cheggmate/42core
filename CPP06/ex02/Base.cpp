#include "Base.hpp"

Base::Base() {
    std::cout << "Base default constructor called" << std::endl;
}

Base::Base(const Base& other) {
    std::cout << "Base copy constructor called" << std::endl;
    *this = other;
}

Base& Base::operator=(const Base& other) {
    std::cout << "Base assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}
