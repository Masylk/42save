#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe    algos;

    if (argc < 2)
        return 1;
    algos.sort(argc - 1, argv + 1);
}