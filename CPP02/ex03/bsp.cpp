#include "Point.hpp"
#include "Fixed.hpp"

// Point::Point() : _x(0), _y(0) {}
// Point::Point(const float x, const float y) : _x(x), _y(y) {}
// Point::Point(const Point& other) : _x(other._x), _y(other._y) {}
// Point& Point::operator=(const Point& other) {
// 	if (this != &other) {
// 		// _x and _y are const, so we can't assign to them
// 		// But we can return *this to allow chained assignments
// 	}
// 	return *this;
// }

// Point::~Point() {}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Vectors relative to point A
    // Vector AC
    float v0x = c.getX().toFloat() - a.getX().toFloat();
    float v0y = c.getY().toFloat() - a.getY().toFloat();
    // Vector AB
    float v1x = b.getX().toFloat() - a.getX().toFloat();
    float v1y = b.getY().toFloat() - a.getY().toFloat();
    // Vector AP
    float v2x = point.getX().toFloat() - a.getX().toFloat();
    float v2y = point.getY().toFloat() - a.getY().toFloat();

    // Compute dot products
    float dot00 = v0x * v0x + v0y * v0y;
    float dot01 = v0x * v1x + v0y * v1y;
    float dot02 = v0x * v2x + v0y * v2y;
    float dot11 = v1x * v1x + v1y * v1y;
    float dot12 = v1x * v2x + v1y * v2y;

    // Compute barycentric coordinates (u and v)
    float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle
    // u > 0, v > 0 and u + v < 1 means it is strictly INSIDE.
    // u >= 0, v >= 0 and u + v <= 1 means it includes the EDGES/VERTICES.
    return (u > 0) && (v > 0) && (u + v < 1);
}
