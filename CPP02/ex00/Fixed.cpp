/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:57:50 by jotong            #+#    #+#             */
/*   Updated: 2025/11/21 00:17:16 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(const Fixed& other) // Creates a new object by copying the internal state (the raw bits) from an existing Fixed object.
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}
Fixed& Fixed::operator=(const Fixed& other) // (const Fixed& other);	Assigns the internal state of an existing Fixed object to another existing Fixed object (e.g., a = b;).
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
