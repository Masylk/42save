#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    RPN p(argv[1]);

    p.print_result();
}