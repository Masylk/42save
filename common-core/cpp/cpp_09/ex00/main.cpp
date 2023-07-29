#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange btc;

    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    btc.setup(argv[1]);
    btc.display();
    return 0;
}