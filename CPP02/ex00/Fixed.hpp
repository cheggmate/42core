/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:39:20 by jotong            #+#    #+#             */
/*   Updated: 2025/11/11 23:57:28 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cctype>

class Fixed
{
	private:
		int					raw_bits;
		static const int	f_bits;
		
	public:
		Fixed () :
			raw_bits(0)
		{} ;
		Fixed (const Fixed& other) // Creates a new object by copying the internal state (the raw bits) from an existing Fixed object.
		{
			Fixed a;
			a = other;
			return ;
		}
		Fixed& operator=(const Fixed& other) // (const Fixed& other);	Assigns the internal state of an existing Fixed object to another existing Fixed object (e.g., a = b;).
		{
			if (this != &other)
			{
				this->raw_bits = other.raw_bits;
			}
			return *this;
		};
		~Fixed()
		{
			delete[] this; // check if this is correct
		}
		
		int getRawBits (void) const
		{
			return this->raw_bits;
		}
		void	setRawBits (int const raw)
		{
			this->raw_bits = raw;
			return ;
		}
};

#endif