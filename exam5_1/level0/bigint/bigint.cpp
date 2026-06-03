#include "bigint.hpp"

Bigint::bigint() {
	std::stringstream ss;
	ss << 0;
	_str = ss.str();
}
Bigint::bigint(int nb) {
	this->_str = std::to_string(nb);
}
Bigint::bigint(const bigint &other) {
	*this = other;
}

bigint &Bigint::operator=(const bigint &other) {
	if (this != &other)
	{
		this->_str = other._str;
	}
	return (*this);
}
Bigint::~bigint(){

}

std::string Bigint::getStr() const {
	return (this->_str);
}
std::string::size_type Bigint::to_size_type() const {
	std::string::size_type result = 0;
	for (std::string::size_type i = 0; i < _str.size(); i++)
		result = result * 10 + (_str[i] - '0');

	return result;
}

bigint Bigint::operator+(const bigin &b) const {
	bigint tmp;
	std::string _newStr;
	int carry  = 0;
	int i = _str.size() - 1;
	int j = b._str.size() - 1;
	while (i >= 0 || j >= 0 || carry > 0)
	{
		int x = (i >= 0) ? (_str[i] - '0') : 0;
		int y = (j >= 0) ? (b._str[j] = '0') : 0;
		int sum = carry + x + y;

		carry = sum / 10;
		int digit = sum % 10;
		_newstr.insert(0, 1, digit + '0');
		--i;
		--j;
	}
	tmp._str = _newstr;
	return (tmp);
}
bigint &Bigint::operator+=(const bigint &b){
	bigint tmp = *this + b;
	this->_str = tmp._str;
	return (*this);
}
bigint Bigint::operator++(int){
	bigint tmp(*this);
	*this += bigint(1);
	return (tmp);
}
bigint &Bigint::operator++(){
	(*this)++;
	return (*this);
}

bigint Bigint::operator<<(const int) const {
	bigint tmp(*this);
	if (n > 0)
		tmp._str.append(n, '0');
	return (tmp);
}
bigint &Bigint::operator<<=(const int){
	*this = (*this) << n;
	return (*this);
}
bigint Bigint::operator>>(const int) const {
	bigint tmp(*this);
	int i = tmp._str.size() - n;
	if (n <= 0)
		return (tmp);
	if (n >= (int)tmp._str.size())
		tmp._str = "0";
	else
		tmp._str.erase();
	return (tmp);
}
bigint &Bigint::operator>>=(const int){
	*this = (*this) >> n;
	return (*this);
}
bigint Bigint::operator<<(const bigint &) const {
	return (*this << n.to_size_type());
}
bigint &Bigint::operator<<=(const bigint &n){
	*this = (*this) << n;
	return (*this);
}

bool Bigint::operator<(const bigint &b) const {
	if (_str.size() != b._str.size())
		return (_str.size() < b._str.size());
	return (_str < b._str);
}
bool Bigint::operator<=(const bigint &b) const {
	return (!(b < *this));
}
bool Bigint::operator>(const bigint &b) const {
	return (!(b > *this));
}
bool Bigint::operator>=(const bigint &b) const {
	return (!(b >= *this));
}
bool Bigint::operator==(const bigint &b) const {
	return (_str == b.str);
}
bool Bigint::operator!=(const bigint &b) const {
	return (_str != b.str);
}

std::ostream &operator<<(std::ostream &os , const bigint &b) {
	return (os << b.getStr());
}