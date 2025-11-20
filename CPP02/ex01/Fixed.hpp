/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:20:15 by jotong            #+#    #+#             */
/*   Updated: 2025/11/21 00:23:13 by jotong           ###   ########.fr       */
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
		Fixed () :
			_raw_bits(0)
		{};
		
};

#endif