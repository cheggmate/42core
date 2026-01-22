#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	public:
		Animal();                             // Default Constructor
		Animal(const Animal& other);    // Copy Constructor
		Animal& operator=(const Animal& other); // Assignment Operator
		virtual ~Animal();                            // Destructor
		virtual void		makeSound() const;
		std::string	getType() const;

	protected:
		std::string	type;
};

#endif
