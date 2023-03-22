#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <climits>
# include <cstdlib>
# include <deque>
# include <iomanip>
# include <algorithm>
# include <iterator>

class PmergeMe
{
private:
    std::list<int> l;
    std::deque<int> d;
    template <typename T>
    void    display(const T& container);
    int     print_error(const char *err) const;
    template<typename T>
    bool    contains(const T &container, int i);
    bool    strIsDigit(const char *str) const;
    void    mergeDeque();
    void    mergeList();
    void    merge(std::list<int>& arr, std::list<int>& left, std::list<int>& right);
    void    mergeInsertionSort(std::list<int> &arr, int threshold);
    void    mergeInsertionSortDeque(std::deque<int>& arr, int left, int right, int threshold);
    void    mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    void    insertionSortDeque(std::deque<int>& arr, int left, int right);
    void    insertionSort(std::list<int>& arr);

public:
    PmergeMe(/* args */);
    PmergeMe(int count, char **tab);
    template<typename T>
    int     setup(T &arr, int count, char **tab);
    int     sort(int argc, char **argv);
    ~PmergeMe();
};

#endif