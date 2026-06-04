#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <cstdlib>

class bigint {
	public:
		bigint();
		bigint(int nb);
		bigint(const bigint &other);
		bigint &operator=(const bigint &other);
		~bigint();

		std::string getStr() const;
		std::string::size_type to_size_type() const;

		bigint operator+(int nb) const;
		bigint operator+(const bigint &b) const;
		bigint &operator+=(const bigint &b);
		bigint operator++(int);
		bigint &operator++();

		bigint operator<<(const int) const;
		bigint &operator<<=(const int);
		bigint operator>>(const int) const;
		bigint &operator>>=(const int);
		bigint operator<<(const bigint &) const;
		bigint &operator<<=(const bigint &);
		bigint operator>>(const bigint &) const;
		bigint &operator>>=(const bigint &);

		bool operator<(const bigint &b) const;
		bool operator>(const bigint &b) const;
		bool operator<=(const bigint &b) const;
		bool operator>=(const bigint &b) const;
		bool operator==(const bigint &b) const;
		bool operator!=(const bigint &b) const;

	private:
		std::string _str;
};

std::ostream &operator<<(std::ostream &os, const bigint &b);

#endif