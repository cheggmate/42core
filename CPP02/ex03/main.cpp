#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

void checkPoint(Point a, Point b, Point c, Point p, std::string name) {
    if (bsp(a, b, c, p))
        std::cout << name << ": Inside" << std::endl;
    else
        std::cout << name << ": Outside" << std::endl;
}


int main( void ) {
	Point a(0, 0), b(10, 0), c(0, 10);

	checkPoint(a, b, c, Point(2, 2), "P1");  		// Expected: Inside
	checkPoint(a, b, c, Point(5, 5), "P2");  		// Expected: Outside
	checkPoint(a, b, c, Point(4.9, 4.9), "P3");  	// Expected: Inside
	checkPoint(a, b, c, Point(5.01, 5.01), "P4");	// Expected: Outside
	checkPoint(a, b, c, Point(0.01, 0.01), "P5");	// Expected: Inside
	

	return 0;
}
