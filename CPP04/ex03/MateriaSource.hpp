#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();                             // Default Constructor
    MateriaSource(const MateriaSource& other);    // Copy Constructor
    MateriaSource& operator=(const MateriaSource& other); // Assignment Operator
    ~MateriaSource();                            // Destructor
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
private:
    AMateria* _templates[4];
};

#endif
