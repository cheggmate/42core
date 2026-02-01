#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {} // Body defined here or in .cpp 
    virtual void learnMateria(AMateria*) = 0; // [cite: 263]
    virtual AMateria* createMateria(std::string const & type) = 0; // [cite: 264]
};

#endif