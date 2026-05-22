#include <fstream>
#include <sstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

const char* BitcoinExchange::ErrorOpeningInputFile::what() const throw() {
    return "Error: could not open database file.";
}

const char* BitcoinExchange::ErrorOpeningProvidedFile::what() const throw() {
    return "Error: could not open file.";
}

BitcoinExchange::BadInputError::BadInputError(const std::string& line) {
    this->_fullMsg = "Error: bad input => " + line;
}

BitcoinExchange::BadInputError::~BadInputError() throw() {}

const char* BitcoinExchange::BadInputError::what() const throw() {
    return this->_fullMsg.c_str();
}

const char* BitcoinExchange::NumberNotPositive::what() const throw() {
    return "Error: not a positive number.";
}

const char* BitcoinExchange::NumberTooLarge::what() const throw() {
    return "Error: too large a number.";
}

BitcoinExchange::BitcoinExchange() {
    std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "Default descructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

void BitcoinExchange::load_input(std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw ErrorOpeningInputFile();
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        size_t comma_pos = line.find(',');
        if (comma_pos != std::string::npos) {
            std::string date = line.substr(0, comma_pos);
            float rate = static_cast<float>(std::strtod(line.substr(comma_pos + 1).c_str(), NULL));
            _database[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::get_rate(const std::string& date) {
    std::map<std::string, float>::iterator it = this->_database.upper_bound(date);

    if (it == this->_database.begin()) {
        return it->second; 
    }
    --it;
    return it->second;
}