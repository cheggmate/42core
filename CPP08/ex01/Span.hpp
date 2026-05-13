#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>

class Span {
public:
    Span(int N);                 
    Span(const Span& other);    // Copy Constructor
    Span& operator=(const Span& other); // Assignment Operator
    ~Span();                            // Destructor
    void            addNumber(int num);
    unsigned int    shortestSpan();
    unsigned int    longestSpan();

    class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NumExceededException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NNotDefined : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class ArrayTooSmallException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    template <typename T>
    void addRange(T begin, T end);

private:
    Span();             // Default Constructor
    unsigned int        _N;
    std::vector<int>    _lst;
    
};

#endif
