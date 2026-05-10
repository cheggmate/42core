#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template <typename T>
void iter(T *arr, size_t arr_len, void (*f)(T const &)) {
    for (size_t i = 0; i < arr_len; i++) {
        f(arr[i]);
    }
}

#endif