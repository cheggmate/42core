#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>
# include <string>

class vect2 {
	public:
		vect2();
		vect2(int num1, int num2);
		vect2(const vect2 &other);
		vect2 &operator=(const vect2 &other);
		~vect2();

		int	getNum(int i) const;

		// Added non-const reference overload to allow syntax like: v1[1] = 12;
		int &operator[](int i);
		int operator[](int i) const;
		
		vect2 operator++(int);
		vect2 &operator++();
		vect2 operator--(int);
		vect2 &operator--(); // Added missing pre-decrement declaration
		
		vect2 &operator+=(const vect2 &other);
		vect2 &operator-=(const vect2 &other);
		vect2 &operator*=(int num);
		
		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const; // Added missing binary subtraction
		vect2 operator*(int num) const;
		
		vect2 operator-() const; // Added missing unary minus (-v2)

		// Added missing boolean comparisons
		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;

	private:
		int num1;
		int	num2;
};

vect2 operator*(int num, const vect2 &vec);
std::ostream &operator<<(std::ostream &os, const vect2 &other);

#endif