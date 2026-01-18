#include "Fixed.hpp"

Fixed:: Fixed() : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
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
