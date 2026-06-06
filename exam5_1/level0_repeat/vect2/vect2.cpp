#include "vect2.hpp"

vect2::vect2() {
	this->x = 0;
	this->y = 0;
}

vect2::vect2(int s_x, int s_y) {
	this->x = s_x;
	this->y = s_y;
}

vect2::vect2(const vect2 &other) {
	(*this) = other;
}

vect2 &vect2::operator=(const vect2 &other) {
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

vect2::~vect2() {

}


int vect2::operator[](int index) const {
	if (index == 0)
		return this->x;
	return this->y;
}

int &vect2::operator[](int index) {
	if (index == 0)
		return this->x;
	return this->y;
}

vect2 vect2::operator+(const vect2 &other) const {
	vect2 tmp(*this);
	tmp.x += other.x;
	tmp.y += other.y;
	return (tmp);
}

vect2 vect2::operator-(const vect2 &other) const {
	vect2 tmp(*this);
	tmp.x -= other.x;
	tmp.y -= other.y;
	return (tmp);
}

vect2 vect2::operator*(const vect2 &other) const {
	vect2 tmp(*this);
	tmp.x *= other.x;
	tmp.y *= other.y;
	return (tmp);
}

vect2 &vect2::operator*(const vect2 &other) {
	this->x *= other.x;
	this->y *= other.y;
	return (*this);
}

vect2 &vect2::operator*=(const vect2 &other) {
	this->x *= other.x;
	this->y *= other.y;
	return (*this);
}
vect2 &vect2::operator+=(const vect2 &other) {
	this->x += other.x;
	this->y += other.y;
	return (*this);
}

vect2 &vect2::operator-=(const vect2 &other){ 
	this->x -= other.x;
	this->y -= other.y;
	return (*this);
}


vect2 &vect2::operator*=(int num) {
	this->x *= num;
	this->y *= num;
	return (*this);
}


bool vect2::operator==(const vect2 &other) const {
	return (this->x == other.x && this->y == other.y);
}

bool vect2::operator!=(const vect2 &other) const {
	return (!(this == &other));
}


vect2 vect2::operator-() const {
	vect2 tmp(*this);
	tmp.x = -tmp.x;
	tmp.y = -tmp.y;
	return (tmp);
}

vect2 vect2::operator*(int num) const {
	vect2 tmp(*this);
	tmp.x = this->x * num;
	tmp.y = this->y * num;
	return (tmp);
}


vect2& vect2::operator++() {
	this->x += 1;
	this->y += 1;
	return (*this);
}

vect2 vect2::operator++(int) {
	vect2 tmp(*this);
	x += 1;
	y += 1;
	return (tmp);
}

vect2& vect2::operator--() {
	this->x -= 1;
	this->y -= 1;
	return (*this);
}

vect2 vect2::operator--(int) {
	vect2 tmp(*this);
	x -= 1;
	y -= 1;
	return (tmp);
}


vect2 operator*(int num, const vect2 &source) {
	return source * num;
}

std::ostream &operator<<(std::ostream &os, const vect2 &source) {
	os <<  "{" << source[0] << ", " << source[1] << "}";
	return os;
}
