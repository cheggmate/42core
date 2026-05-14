#include "Span.hpp"
#include <vector>
#include <list>

const char* Span::NotFoundException::what() const throw() {
    return "Element not found in container.";
}

const char* Span::NumExceededException::what() const throw() {
    return "Max number of elements reach in container.";
}

const char* Span::NNotDefined::what() const throw() {
    return "N not defined";
}

const char* Span::ArrayTooSmallException::what() const throw() {
    return "Less than 2 elements in container. No span possible.";
}

Span::Span() {
    
    std::cout << "Span default constructor called" << std::endl;
    throw NNotDefined();
}

Span::Span(int max) {
    this->_N = max;
    return ;
}

Span::Span(const Span& other) {
    std::cout << "Span copy constructor called" << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Span assignment operator called" << std::endl;
    if (this != &other) {
        this->_N = other._N;
        this->_lst = other._lst;
    }
    return *this;
}

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
}

void    Span::addNumber(int num) {
    if (this->_lst.size() == _N)
        throw NumExceededException();
    this->_lst.push_back(num);
}

unsigned int Span::longestSpan() {
    if (this->_lst.size() < 2)
        throw ArrayTooSmallException();
    int min = *std::min_element(_lst.begin(), _lst.end());
    int max = *std::max_element(_lst.begin(), _lst.end());
    return static_cast<unsigned int>(max - min);
}

unsigned int    Span::shortestSpan() {
    if (this->_lst.size() < 2)
        throw ArrayTooSmallException();
    std::vector<int> sorted = _lst;
    std::sort(sorted.begin(), sorted.end());

    unsigned int min_diff = static_cast<unsigned int>(sorted[1] - sorted[0]);

    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        unsigned int current_diff = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    return min_diff;
}
