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
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        size_t range_size = std::distance(begin, end);

        if (_lst.size() + range_size > _N)
            throw std::exception();

        _lst.insert(_lst.end(), begin, end);
    }

private:
    Span();             // Default Constructor
    unsigned int        _N;
    std::vector<int>    _lst;
    
};

#endif
