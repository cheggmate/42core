
#include "vect2.hpp"

vect2::vect2() {
	this->num1 = 0;
	this->num2 = 0;
}

vect2::vect2(int num1, int num2) {
	this->num1 = num1;
	this->num2 = num2;
}

vect2::vect2(const vect2 &other) {
	this->num1 = other.num1;
	this->num2 = other.num2;
}

vect2 &vect2::operator=(const vect2 &other) {
	if (this != &other)
	{
		this->num1 = other.num1;
		this->num2 = other.num2;
	}
	return (*this);
}

vect2::~vect2() {

}

// Non-const version allows assignment like: v1[1] = 12;
int &vect2::operator[](int i) {
	if (i == 0)
		return (this->num1);
	return (this->num2);
}

int	vect2::operator[](int i) const {
	if (i == 0)
		return (this->num1);
	return (this->num2);
}

vect2 vect2::operator++(int) {
	vect2 tmp(*this);
	this->num1 = this->num1 + 1;
	this->num2 = this->num2 + 1;
	return (tmp);
}

vect2 &vect2::operator++() {
	this->num1 = this->num1 + 1;
	this->num2 = this->num2 + 1;
	return (*this);
}

vect2 vect2::operator--(int) {
	vect2 tmp(*this);
	this->num1 = this->num1 - 1;
	this->num2 = this->num2 - 1;
	return (tmp);
}

vect2 &vect2::operator--() {
	this->num1 = this->num1 - 1;
	this->num2 = this->num2 - 1;
	return (*this);
}

// Fixed: changed 'vect' to 'vect2'
vect2 &vect2::operator+=(const vect2 &other) {
	this->num1 = this->num1 + other.num1;
	this->num2 = this->num2 + other.num2;
	return (*this);
}

// Fixed: changed 'vect' to 'vect2'
vect2 &vect2::operator-=(const vect2 &other) {
	this->num1 = this->num1 - other.num1;
	this->num2 = this->num2 - other.num2;
	return (*this);
}

int vect2::getNum(int i) const {
	if (i == 0) 
		return (this->num1);
	return (this->num2);
}

vect2 &vect2::operator*=(int num) {
	this->num1 = this->num1 * num;
	this->num2 = this->num2 * num;
	return (*this);
}

vect2 vect2::operator+(const vect2 &other) const {
	vect2 tmp(*this);
	tmp.num1 = tmp.num1 + other.num1;
	tmp.num2 = tmp.num2 + other.num2;
	return (tmp);
}

// Added binary subtraction operator
vect2 vect2::operator-(const vect2 &other) const {
	vect2 tmp(*this);
	tmp.num1 = tmp.num1 - other.num1;
	tmp.num2 = tmp.num2 - other.num2;
	return (tmp);
}

// Added const to match the updated header declaration
vect2 vect2::operator*(int num) const {
	vect2 tmp(*this);
	tmp.num1 = tmp.num1 * num;
	tmp.num2 = tmp.num2 * num;
	return (tmp);
}

// Added unary minus operator for -v2
vect2 vect2::operator-() const {
	return (vect2(-this->num1, -this->num2));
}

// Added boolean operators
bool vect2::operator==(const vect2 &other) const {
	return (this->num1 == other.num1 && this->num2 == other.num2);
}

bool vect2::operator!=(const vect2 &other) const {
	return (!(*this == other));
}

// Global non-member friend function for left-hand scalar multi (e.g. 3 * v2)
vect2 operator*(int num, const vect2 &vec) {
	return (vec * num);
}

// Fixed: write output to 'os' stream instead of 'std::cout' directly
std::ostream &operator<<(std::ostream &os, const vect2 &other) {
	os << "{" << other[0] << ", " << other[1] << "}";
	return (os);
}

