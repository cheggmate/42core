#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

class BitcoinExchange {
public:
    BitcoinExchange();                             // Default Constructor
    BitcoinExchange(const BitcoinExchange& other);    // Copy Constructor
    BitcoinExchange& operator=(const BitcoinExchange& other); // Assignment Operator
    ~BitcoinExchange();                            // Destructor

private: 
};

#endif
