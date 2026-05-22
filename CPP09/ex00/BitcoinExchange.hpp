#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <exception>
# include <string>

class BitcoinExchange {
private: 
    std::map<std::string, float> _database;

public:
    BitcoinExchange();                             
    BitcoinExchange(const BitcoinExchange& other);    
    BitcoinExchange& operator=(const BitcoinExchange& other); 
    ~BitcoinExchange();                            

    void load_input(std::string filename);
    float get_rate(const std::string& date);
    
    class ErrorOpeningInputFile : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class ErrorOpeningProvidedFile : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class BadInputError : public std::exception {
    private:
        std::string _fullMsg;
    public:
        BadInputError(const std::string& line);
        virtual ~BadInputError() throw();
        virtual const char* what() const throw();
    };
    
    class NumberNotPositive : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NumberTooLarge : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif