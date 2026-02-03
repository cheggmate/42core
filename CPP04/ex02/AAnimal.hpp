#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {
	public:
		AAnimal();			               // Default Constructor
		AAnimal(const AAnimal& other);    // Copy Constructor
		AAnimal& operator=(const AAnimal& other); // Assignment Operator
		virtual ~AAnimal();   				// Destructor
		virtual void		makeSound() const = 0;
		std::string	getType() const;

	protected:
		std::string	type;
		                         
};
#endif
