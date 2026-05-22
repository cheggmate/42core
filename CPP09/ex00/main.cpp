#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

std::string trim_whitespace(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2000 || year > 2026 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeap && day > 29) return false;
        if (!isLeap && day > 28) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl; // Match exact usage error requirement
        return 1;
    }

    BitcoinExchange exchange;
    try {
        exchange.load_input("data.csv");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::ifstream evalFile(argv[1]);
    if (!evalFile.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    bool isHeader = true;

    while (std::getline(evalFile, line)) {
        if (line.empty()) continue;
        
        size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string datePart = trim_whitespace(line.substr(0, pipe_pos));
        std::string valuePart = trim_whitespace(line.substr(pipe_pos + 1));

        // Dynamically discard the header line if it contains the literal text "date"
        if (isHeader && datePart == "date") {
            isHeader = false;
            continue;
        }
        isHeader = false;

        if (!isValidDate(datePart)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        char* endptr;
        double val = std::strtod(valuePart.c_str(), &endptr);
        if (*endptr != '\0' || valuePart.empty()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (val < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = exchange.get_rate(datePart);
        std::cout << datePart << " => " << val << " = " << (val * rate) << std::endl;
    }

    evalFile.close();
    return 0;
}