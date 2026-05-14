#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}
