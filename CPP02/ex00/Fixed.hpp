/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:39:20 by jotong            #+#    #+#             */
/*   Updated: 2025/12/25 22:37:13 by jotong           ###   ########.fr       */
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
		int					_raw_bits;
		static const int	_f_bits = 8;
		
	public:
		Fixed ();
		Fixed (const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
};

#endif