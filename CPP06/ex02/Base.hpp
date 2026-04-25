#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class Base {
public:
    virtual ~Base();                            // Destructor
    Base * generate(void);
    void identify(Base* p);
    void identify(Base& p);

protected:
    Base();                             // Default Constructor
    Base(const Base& other);    // Copy Constructor
    Base& operator=(const Base& other); // Assignment Operator
};

#endif
