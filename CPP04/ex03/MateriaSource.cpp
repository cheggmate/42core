#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
    std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
        this->_templates[i] = NULL; // Crucial to prevent undefined behavior [cite: 242]
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    
	if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (this->_templates[i])
                delete this->_templates[i]; // Clean up existing memory
            if (other._templates[i])
                this->_templates[i] = other._templates[i]->clone(); // Deep copy [cite: 253, 266]
            else
                this->_templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
	 for (int i = 0; i < 4; i++) {
        if (this->_templates[i]) {
            delete this->_templates[i]; // Free the clones created by learnMateria [cite: 255]
        }
    }
}

void    MateriaSource::learnMateria(AMateria* m) {
    int	i;

	i = 0;
	if (!m)
		return ;
	while (i < 4 && this->_templates[i] != NULL)
		i++;
	if (i == 4)
		return ;
	else {
		AMateria* new_clone;
		new_clone = m->clone();
		// if (m->getType() == "ice") {
		// 	new_clone = m->clone();
		// }
		this->_templates[i] = new_clone;
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        // Check if the slot is occupied and if the type matches the request
        if (this->_templates[i] != NULL && this->_templates[i]->getType() == type) {
            // Return a new clone of the stored template [cite: 269]
            return (this->_templates[i]->clone());
        }
    }
    return (0);
}
