#include "Fixed.hpp"

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_raw_bits = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Int to fixed-point : Shift left by _f_bits to multiply by 2^8
Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = input << _f_bits;
}

// Float to fixed-point : Multiply by 2^8 and round
Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = roundf(input * (1 << _f_bits));
}

// Fixed-point to int: Shift right by _f_bits to divide by 2^8
int Fixed::toInt(void) const
{
	return this->_raw_bits >> _f_bits;
}

// Convert fixed-point to float
// Divide by 2^8
float Fixed::toFloat(void) const
{
	return (float)this->_raw_bits / (1 << _f_bits);
}

int Fixed::getRawBits(void) const
{
	return this->_raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}

// Overload << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}