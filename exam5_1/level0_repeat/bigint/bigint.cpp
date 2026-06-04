#include "bigint.hpp"

bigint::bigint() {
	std::stringstream ss;
	ss << 0;
	_str = ss.str();
}


bigint::bigint(int nb) {
	std::stringstream ss;
	ss << nb;
	this->_str = ss.str();
}


bigint::bigint(const bigint &other) {
	*this = other;
}


bigint &bigint::operator=(const bigint &other) {
	if (this != &other)
	{
		this->_str = other._str;
	}
	return (*this);
}


bigint::~bigint() {

}



std::string bigint::getStr() const {
	return (this->_str);
}


std::string::size_type bigint::to_size_type() const {
	std::string::size_type result = 0;
	for (std::string::size_type i = 0; i < _str.size(); i++)
		result = result * 10 + (_str[i] - '0');
	return result;
}


bigint bigint::operator+(int nb) const {
	return (*this + bigint(nb));
}


bigint bigint::operator+(const bigint &b) const {
	bigint tmp;
	std::string _newstr;
	int carry = 0;
	int i = _str.size()-1;
	int j = b._str.size() - 1;
	while (i >= 0 || j >= 0 || carry > 0)
	{
		int x = (i >= 0) ? (_str[i] - '0') : 0;
		int y = (j >= 0) ? (b._str[j] - '0') : 0;
		int sum = carry + x + y;

		carry = sum / 10;
		int digit = sum % 10;
		_newstr.insert(0, 1, digit + '0');
		if (i >= 0) --i;
		if (j >= 0) --j;
	}
	tmp._str = _newstr;
	return (tmp);
}

bigint &bigint::operator+=(const bigint &b) {
	bigint tmp = *this + b;
	this->_str = tmp._str;
	return (*this);
}

bigint bigint::operator++(int) {
	bigint tmp(*this);
	*this += bigint(1);
	return (*this);
}

bigint &bigint::operator++() {
	*this += bigint(1);
	return (*this);
}

bigint bigint::operator<<(const int n) const {
	bigint tmp(*this);
	if (n > 0)
		tmp._str.append(n, '0');
	return (tmp);
}


bigint &bigint::operator<<=(const int n) {
	*this = (*this) << n;
	return (*this);
}

bigint bigint::operator>>(const int n) const {
	bigint tmp(*this);
	if (n <= 0)
		return (tmp);
	if (n >= (int)tmp._str.size())
		tmp._str = "0";
	else {
		int i = tmp._str.size() - n;
		tmp._str.erase(i);
	}
	return (tmp);
}


bigint &bigint::operator>>=(const int n) {
	*this = (*this) >> n;
	return (*this);
}


bigint bigint::operator<<(const bigint &n) const {
	return (*this << n.to_size_type());
}

bigint &bigint::operator<<=(const bigint &n) {
	*this = (*this) << n;
	return (*this);
}

bigint bigint::operator>>(const bigint &n) const {
	return (*this >> n.to_size_type());
}

bigint &bigint::operator>>=(const bigint &n) {
	*this = (*this) >> n.to_size_type();
	return (*this);
}

bool bigint::operator<(const bigint &b) const {
	if (_str.size() != b._str.size())
		return (_str.size() < b._str.size());
	return (_str < b._str);
}


bool bigint::operator>(const bigint &b) const {
	if (_str.size() != b._str.size())
		return (_str.size() > b._str.size());
	return (_str > b._str);
}

bool bigint::operator<=(const bigint &b) const {
	return (!(b < *this));
}


bool bigint::operator>=(const bigint &b) const {
	return (!(*this < b));
}


bool bigint::operator==(const bigint &b) const {
	return (_str == b._str);
}


bool bigint::operator!=(const bigint &b) const {
	return (_str != b._str);
}



std::ostream &operator<<(std::ostream &os, const bigint &b) {
	return (os << b.getStr());
}