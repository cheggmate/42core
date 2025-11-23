/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:20:15 by jotong            #+#    #+#             */
/*   Updated: 2025/11/24 00:10:13 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

class Fixed
{
	private:
		int					_raw_bits;
		static const int	_f_bits = 8;
	public:
		Fixed () :
			_raw_bits(0)
		{
			std::cout << "Default constructor called" << std::endl;
		} ;
		Fixed (const int input);
		Fixed (const float input);
		Fixed (const Fixed& other); // Creates a new object by copying the internal state (the raw bits) from an existing Fixed object.
		
		Fixed& operator=(const Fixed& other); // (const Fixed& other);	Assigns the internal state of an existing Fixed object to another existing Fixed object (e.g., a = b;).
		~Fixed();
		int	toInt(void) const;
		float toFloat (void) const;
		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
};

#endif