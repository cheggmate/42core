#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		// _x and _y are const, so we can't assign to them
		// But we can return *this to allow chained assignments
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}
