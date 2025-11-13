/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:57:50 by jotong            #+#    #+#             */
/*   Updated: 2025/11/14 00:35:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const Fixed& other) // Creates a new object by copying the internal state (the raw bits) from an existing Fixed object.
{
	this->setRawBits(other.getRawBits());
}
Fixed& Fixed::operator=(const Fixed& other) // (const Fixed& other);	Assigns the internal state of an existing Fixed object to another existing Fixed object (e.g., a = b;).
{
	if (this != &other)
	{
		this->_raw_bits = other._raw_bits;
	}
	return *this;
};
Fixed:: ~Fixed()
{
	std::cout << "Calling Destructor..." << std::endl;
}

int Fixed::getRawBits (void) const
{
	return this->_raw_bits;
}
void	Fixed::setRawBits (int const raw)
{
	this->_raw_bits = raw;
	return ;
}
		
