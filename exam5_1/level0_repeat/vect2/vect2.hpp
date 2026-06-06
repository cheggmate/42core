#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>
# include <algorithm>
# include <string>

class vect2 {
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &other);
		vect2 &operator=(const vect2 &other);
		~vect2();

		int operator[](int index) const;
		int &operator[](int index);

		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const;
		vect2 operator*(const vect2 &other) const;
		vect2 &operator*(const vect2 &other);
		
		vect2 &operator*=(const vect2 &other);
		vect2 &operator+=(const vect2 &other);
		vect2 &operator-=(const vect2 &other);

		vect2 &operator*=(int num);

		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;

		vect2 operator-() const;
		vect2 operator*(int num) const;

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

	private:
		int x;
		int y;
};
#endif

vect2 operator*(int num, const vect2 &source);
std::ostream &operator<<(std::ostream &os, const vect2 &source);