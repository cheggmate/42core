#include "vect2.hpp"

vect2::vect2() {

}
vect2::vect2(int num1, int num2) {
	this->num1 = num1;
	this->num2 = num2;
}
vect2::vect2(const vect2 &source){
	this->num1 = source.num1;
	this->num2 = source.num2;

}
vect2 &vect2::operator=(const vect2 &source){
	if (this!= &source){
		this->num1 = source.num1;
		this->num2 = source.num2;
	}
	return (*this);
}
vect2::~vect2(){

}

int vect2::getNum(int i) const{
	if (i == 0) 
		return (this->num1);
	return (this->num2);
}

int &vect2::operator[](int i){
	if (i==0) {
		return (this->num1);
	
	}
	return (this->num2);
}
int vect2::operator[](int i) const{
	if (i == 0) 
		return (this->num1);
	return (this->num2);
}

vect2 vect2::operator++(int){
	vect2 tmp(*this);
	tmp.num1 = this->num1 + 1;
	tmp.num2 = this->num2 + 1;
	return (tmp);
}
vect2 &vect2::operator++(){
	this->num1 = this->num1 +1;
	this->num2 = this->num2 + 1;
	return (*this);
}
vect2 vect2::operator--(int){
	vect2 tmp(*this);
	tmp.num1 = tmp.num1 - 1;
	tmp.num2 = tmp.num2 - 1;
	return (tmp);
}
vect2 &vect2::operator--(){

	this->num1 = this->num1 - 1;
	this->num2 = this->num2 - 1;
	return (*this);
}

vect2&vect2::operator+=(const vect2 &other){
	this->num1 = this->num1 + other.num1;
	this->num2 = this->num2 + other.num2;
	return (*this);
}
vect2 &vect2::operator-=(const vect2 &other){
	this->num1 = this->num1 - other.num1;
	this->num2 = this->num2 - other.num2;
	return (*this);
}
vect2 &vect2::operator*=(int num){
	this->num1 = this->num1 * num;
	this->num2 = this->num2 * num;
	return (*this);
}

vect2 vect2::operator+(const vect2 &other) const{
	vect2 tmp(*this);
	tmp.num1 = tmp.num1 + other.num1;
	tmp.num2 = tmp.num2 + other.num2;
	return (tmp);
}
vect2 vect2::operator-(const vect2 &other) const{
	vect2 tmp(*this);
	tmp.num1 = tmp.num1 - other.num1;
	tmp.num2 = tmp.num2 - other.num2;
	return (tmp);
}
vect2 vect2::operator*(int num) const{
	vect2 tmp(*this);
	tmp.num1 = tmp.num1 * num;
	tmp.num2 = tmp.num2 * num;
	return (tmp);
}

vect2 vect2::operator-() const{
	return(vect2(-this->num1, -this->num2));
}

bool vect2::operator==(const vect2 &other) const{
	return(this->num1 == other.num1 && this->num2 == other.num2);
}
bool vect2::operator!=(const vect2 &other) const{
	return (!(*this == other));
}

vect2 operator*(int num, const vect2 &vec) {
	return (vec * num);
}

std::ostream &operator<<(std::ostream &os, const vect2 &other) {
	os << "{" << other[0] << ", " << other[1] << "}";
	return(os);
}
