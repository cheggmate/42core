#include <fstream>
#include "BitcoinExchange.hpp"

const char* BitcoinExchange::ErrorOpeningInputFile::what() const throw() {
    return "Error: could not open database file.";
}

const char* BitcoinExchange::ErrorOpeningProvidedFile::what() const throw() {
    return "Error: could not open file.";
}

BitcoinExchange::BadInputError(const std::string& line) {
    this->_fullMsg = "Error: bad input => " + line;
}

const char* BitcoinExchange::BadInputError::what() const throw() {
    return this->_fullMsg.c_str();
}

const char* BitcoinExchange::NumberNotPositive::what() const throw() {
    return "Error: not a positive number.";
}

const char* BitcoinExchange::ErrorOpeningProvidedFile::what() const throw() {
    return "Error: too large a number.";
}

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::load_input(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw ErrorOpeningInputFile();
    std::string line;
    std::getline(file, line); // Skip the header line
    while (std::getline(file, line)) {
        size_t comma_pos = line.find(',');
        if (comma_pos != std::string::npos) {
            std::string date = line.substr(0, comma_pos);
            float rate = static_cast<float>(atof(line.substr(comma_pos + 1).c_str()));
            _database[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::get_rate(const std::string& date) {
    // upper_bound returns the first element strictly GREATER than the date
    std::map<std::string, float>::iterator it = this->_database.upper_bound(date);

    if (it == this->_database.begin()) {
        // You might want to check if the exact date is actually the first one
        // or handle this as a "date too early" error
        return it->second; 
    }
    // Move back one step to get the closest date that is <= your input date
    --it;
    return it->second;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange assignment operator called" << std::endl;
    if (this != &other) {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}


