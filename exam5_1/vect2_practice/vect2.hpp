#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>
# include <string>

class vect2 {
	private:
		int num1;
		int num2;

	public:
		vect2();
		vect2(int num1, int num2);
		vect2(const vect2 &source);
		vect2 &operator=(const vect2 &source);
		~vect2();

		int getNum(int i) const;
		int operator[](int i) const;
		int &operator[](int i);

		vect2 operator++(int);
		vect2 &operator++();
		vect2 operator--(int);
		vect2 &operator--();

		vect2 &operator+=(const vect2 &source);
		vect2 &operator-=(const vect2 &source);
		vect2 &operator*=(int num);

		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const;
		vect2 operator*(int num) const;

		vect2 operator-() const;

		bool operator==(const vect2 &source) const;
		bool operator!=(const vect2 &source) const;


};

vect2 operator*(int num, const vect2 &source);
std::ostream &operator<<(std::ostream &os , const vect2 &source);
#endif