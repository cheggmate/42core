#include "Fixed.hpp"

Fixed::Fixed() : _raw_bits(0)
{};

Fixed::Fixed(const Fixed& other)
{
    this->setRawBits(other.getRawBits());
}

// Int to fixed-point : Shift left by _f_bits to multiply by 2^8
Fixed::Fixed(const int input)
{
    this->_raw_bits = input << _f_bits;
}

// Float to fixed-point : Multiply by 2^8 and round
Fixed::Fixed(const float input)
{
    this->_raw_bits = roundf(input * (1 << _f_bits));
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}	

// Fixed-point to int: Shift right by _f_bits to divide by 2^8
int Fixed::toInt(void) const
{
    return this->_raw_bits >> _f_bits;
}

// Convert fixed-point to float: Divide by 2^8
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

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	long long temp = (long long)this->_raw_bits + (long long)other._raw_bits;
	result._raw_bits = temp;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	long long temp = (long long)this->_raw_bits - (long long)other._raw_bits;
	result._raw_bits = temp;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long long temp = (long long)this->_raw_bits * (long long)other._raw_bits;
	result._raw_bits = (temp >> _f_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long temp = (long long)this->_raw_bits << _f_bits;
	
	if (other._raw_bits == 0)
	{
		std::cerr << "Error: Division by zero, returning default value" << std::endl;
		return result;
	}
	result._raw_bits = (temp / other._raw_bits);
	return result;
}

Fixed& Fixed::operator++()
{
	int		tempRawBits;
	tempRawBits = this->getRawBits();
	tempRawBits += 1;
	this->setRawBits(tempRawBits);
	return *this;
}

// Saves a copy, increments, then returns the old copy.
Fixed Fixed::operator++(int)
{
	int		tempRawBits;
	Fixed temp(*this);
	tempRawBits = this->getRawBits();
	tempRawBits += 1;
	this->setRawBits(tempRawBits);
	return temp;
}

Fixed& Fixed::operator--()
{
	int		tempRawBits;
	tempRawBits = this->getRawBits();
	tempRawBits -= 1;
	this->setRawBits(tempRawBits);
	return *this;
}

// Saves a copy, decrements, then returns the old copy.
Fixed Fixed::operator--(int)
{
	int		tempRawBits;
	Fixed temp(*this);
	tempRawBits = this->getRawBits();
	tempRawBits -= 1;
	this->setRawBits(tempRawBits);
	return temp;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->_raw_bits > other._raw_bits;
}
bool Fixed::operator<(const Fixed& other) const {
	return this->_raw_bits < other._raw_bits;
}
bool Fixed::operator>=(const Fixed& other) const {
	return this->_raw_bits >= other._raw_bits;

}
bool Fixed::operator<=(const Fixed& other) const {
	return this->_raw_bits <= other._raw_bits;
}
bool Fixed::operator==(const Fixed& other) const {
	return this->_raw_bits == other._raw_bits;
}
bool Fixed::operator!=(const Fixed& other) const {
	return this->_raw_bits != other._raw_bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
