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
		Fixed() : _raw_bits(0);
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& other);
		
		Fixed& operator=(const Fixed& other);
		~Fixed();
		
		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif