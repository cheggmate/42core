#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	// Fixed const c( Fixed( 5.05f ) / Fixed( 0 ) );
	// std::cout << c << std::endl;

	// --- Arithmetic Tests ---
	std::cout << "\n--- Arithmetic Tests ---" << std::endl;
	Fixed c(2);
	Fixed d(4.2f);

	std::cout << "c: " << c << " | d: " << d << std::endl;
	std::cout << "c + d = " << (c + d) << std::endl;
	std::cout << "d - c = " << (d - c) << std::endl;
	std::cout << "c * d = " << (c * d) << std::endl;
	std::cout << "d / c = " << (d / c) << std::endl;

	// --- Comparison Tests ---
	std::cout << "\n--- Comparison Tests ---" << std::endl;
	Fixed const e(10);
	Fixed const f(20);

	std::cout << "e: " << e << " | f: " << f << std::endl;
	std::cout << "e > f  : " << (e > f) << std::endl;
	std::cout << "e < f  : " << (e < f) << std::endl;
	std::cout << "e == f : " << (e == f) << std::endl;
	std::cout << "e != f : " << (e != f) << std::endl;

	// --- Min/Max Tests ---
	std::cout << "\n--- Min/Max Tests ---" << std::endl;
	std::cout << "min(e, f) : " << Fixed::min( e, f ) << std::endl;
	std::cout << "max(e, f) : " << Fixed::max( e, f ) << std::endl;

	// --- Increment/Decrement (The Smallest Epsilon) ---
	std::cout << "\n--- Epsilon Step Tests ---" << std::endl;
	Fixed g(0);
	std::cout << "Start : " << g << std::endl;
	std::cout << "Pre++ : " << ++g << " (Should be 0.00390625)" << std::endl;
	std::cout << "Pre-- : " << --g << " (Should be 0)" << std::endl;
	return 0;
}