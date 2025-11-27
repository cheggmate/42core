#include "Fixed.hpp"

Fixed::Fixed(const Fixed& other) // Creates a new object by copying the internal state (the raw bits) from an existing Fixed object.
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}
Fixed& Fixed::operator=(const Fixed& other) //	Assigns the internal state of an existing Fixed object to another existing Fixed object (e.g., a = b;).
{
	if (this != &other)
	{
		int	other_bits;

		std::cout << "Copy assignment operator called" << std::endl;
		other_bits = other.getRawBits();
		this->_raw_bits = other_bits;
	}
	return *this;
};

Fixed:: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt (void) const
{

}

Fixed::Fixed (const int input)
{
	this->_raw_bits = input; // TODO: map this to the  corresponding fixed val
}
Fixed::Fixed (const float input)
{
	this->_raw_bits = input; // Todo:  map this to the corresponding fixed value
}

int Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw_bits;
}
void	Fixed::setRawBits (int const raw)
{
	this->_raw_bits = raw;
	return ;
}
