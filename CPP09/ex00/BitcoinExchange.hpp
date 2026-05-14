#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <exception>
# include <string>

class BitcoinExchange {
public:
    BitcoinExchange();                             // Default Constructor
    BitcoinExchange(const BitcoinExchange& other);    // Copy Constructor
    BitcoinExchange& operator=(const BitcoinExchange& other); // Assignment Operator
    ~BitcoinExchange();                            // Destructor
    load_input(std::string filename);
    float get_rate(const std::string& date);
    
    class ErrorOpeningInputFile : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class ErrorOpeningProvidedFile : public std::exception {
    public:
        virtual const char* what() const throw();
    }

    class BadInputError : public std::exception {
    private:
        std::string _fullMsg;
    public:
        BadInputError(const std::string& line);
        virtual ~BadInputError() throw();
        virtual const char* what() const throw();
    }
    
    class NumberNotPositive :public std::exception {
    public:
        virtual const char* what() const throw();
    }

    class NumberTooLarge :public std::exception {
    public:
        virtual const char* what() const throw();
    }
};

private: 
    std::map    _database;
};

#endif
