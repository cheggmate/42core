#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();                             // Default Constructor
		WrongAnimal(const WrongAnimal& other);    // Copy Constructor
		WrongAnimal& operator=(const WrongAnimal& other); // Assignment Operator
		~WrongAnimal();                            // Destructor
		void		makeSound() const;
		std::string	getType() const;

	protected:
		std::string	type;
};

#endif
