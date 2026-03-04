#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	public:
		
		
		virtual void		makeSound() const;
		std::string	getType() const;

	protected:
		std::string	type;
	private:
		Animal() = delete;               // Default Constructor
		Animal(const Animal& other);    // Copy Constructor
		Animal& operator=(const Animal& other); // Assignment Operator
		virtual ~Animal();                            // Destructor
};

#endif
