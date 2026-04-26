#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int    _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _size(n) {
        if (n > 0)
            _data = new T[n]();
        else
            _data = NULL;
    }

    Array(const Array& other) : _data(NULL), _size(0) {
        *this = other;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            if (_data)
                delete[] _data;
            _size = other._size;
            if (_size > 0) {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _data[i] = other._data[i];
            } else {
                _data = NULL;
            }
        }
        return *this;
    }

    ~Array() {
        if (_data)
            delete[] _data;
    }

    T& operator[](unsigned int index) {
        if (index >= _size)
            throw OutOfBoundsException();
        return _data[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw OutOfBoundsException();
        return _data[index];
    }

    unsigned int size() const {
        return _size;
    }

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index is out of bounds!";
        }
    };
};

#endif
