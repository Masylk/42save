#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <string>

class BitcoinExchange
{
private:
    std::vector<std::vector<std::string> >  data;
    std::vector<std::string>                output;
public:
    BitcoinExchange(/* args */);
    BitcoinExchange(const BitcoinExchange &cpy);
    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    int             setup(const char *filename);
    int             check_open(const std::ifstream &file) const;
    int             check_date(const std::string &date) const;
    void            parseInput(std::ifstream &input);
    void            display();
    std::string     getExchangeRate(const std::string &date, float value);
    std::string     find_date(std::ifstream &file, const std::string &date);

    //utils
    std::vector<std::string> split(const std::string &str, const char *delimiter) const;
    void            db_display() const;

};

#endif