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
		Fixed() : _raw_bits(0) {}
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& other);
		
		Fixed& operator=(const Fixed& other);
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		~Fixed();
		
		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		static const Fixed& max(const Fixed& a, const Fixed& b) {
			return (a.getRawBits() > b.getRawBits()) ? a : b;
		}
		static Fixed& max(Fixed& a, Fixed& b) {
			return (a.getRawBits() > b.getRawBits()) ? a : b;
		}
		static const Fixed& min(const Fixed& a, const Fixed& b) {
			return (a.getRawBits() < b.getRawBits()) ? a : b;
		}
		static Fixed& min(Fixed& a, Fixed& b) {
			return (a.getRawBits() < b.getRawBits()) ? a : b;
		}	
		Fixed& operator++(); // Prefix ++a
		Fixed operator++(int); // Postfix a++
		Fixed& operator--(); // Prefix --a
		Fixed operator--(int); // Postfix a--

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);
#endif
