#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */): l(), d()
{
}

int    PmergeMe::print_error(const char *err) const
{
    std::cerr << err << std::endl;
    return 1;
}

bool    PmergeMe::strIsDigit(const char *str) const
{
    int i = 0;

    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

template<typename T>
int     PmergeMe::setup(T &arr, int count, char **tab)
{
    int i = 0;
    double  check;
    int     elem;
    while (count)
    {
        if (!strIsDigit(tab[i]))
            return print_error("Error: invalid number");
        check = std::atof(tab[i]);
        if (check > INT_MAX || check < INT_MIN)
            return print_error("Error : int Overflow");
        elem = static_cast<int>(check);
        if (elem < 0)
            return print_error("Error: negative number");
        if (!contains(arr, elem))
            arr.push_back(static_cast<int>(elem));
        count--;
        i++;
    }
    return arr.size();
}

int     PmergeMe::sort(int argc, char **argv)
{
    int count = 0;

    clock_t start1 = clock();
    count = setup(l, argc, argv);
    std::cout << "List" <<std::endl;
    std::cout << "Before:  ";
    display(l);
    std::cout << "After:  ";
    mergeList();
    display(l);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << std::endl;

    clock_t start2 = clock();    
    count = setup(d, argc, argv);
    std::cout << "Deque" << std::endl;
    std::cout << "Before:  ";
    display(d);
    std::cout << "After:  ";
    mergeDeque();
    display(d);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;

    std::cout << std::endl;

    // display the containers process time
    std::cout << "Time to process a range of " << count
    << " elements with std::list : " << std::fixed << std::setprecision(3) << time1
    << "us" << std::endl;

    std::cout << "Time to process a range of " << count
    << " elements with std::deque : " << std::fixed << std::setprecision(3) << time2
    << "us" << std::endl;
    return 0;
}


void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> temp(right - left + 1);
    
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int>& arr,
int left, int right, int threshold) {
    if (left >= right) {
        return;
    }
    if (right - left + 1 <= threshold) {
        insertionSortDeque(arr, left, right);
    }
    else {
        int mid = (left + right) / 2;
        mergeInsertionSortDeque(arr, left, mid, threshold);
        mergeInsertionSortDeque(arr, mid + 1, right, threshold);
        mergeDeque(arr, left, mid, right);
    }
}

void    PmergeMe::mergeDeque()
{
    int n = d.size();

    int threshold = 4; // set threshold for insertion sort
    mergeInsertionSortDeque(d, 0, n - 1, threshold);
}
// DEQUE ALGORITHM

// LIST ALGORITHMS

void PmergeMe::merge(std::list<int>& arr, std::list<int>& left, std::list<int>& right) {
    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left <= *it_right) {
            arr.push_back(*it_left);
            it_left++;
        }
        else {
            arr.push_back(*it_right);
            it_right++;
        }
    }

    while (it_left != left.end()) {
        arr.push_back(*it_left);
        it_left++;
    }

    while (it_right != right.end()) {
        arr.push_back(*it_right);
        it_right++;
    }
}

void PmergeMe::insertionSort(std::list<int>& arr) 
{
    std::list<int>::iterator i = arr.begin();
    i++;
    for (; i != arr.end(); i++) {
        std::list<int>::iterator j = i;
        j--;
        int key = *i;
        while (j != arr.begin() && *j > key) {
            std::list<int>::iterator prev = j;
            prev--;
            *j = *prev;
            j--;
        }
        if (*j > key) {
            *j = key;
            key = *i;
        }
        else {
            *j = key;
        }
    }
}

void PmergeMe::mergeInsertionSort(std::list<int> &arr, int threshold) {
    int n = arr.size();
    if (n <= 1) {
        return;
    }
    if (n <= threshold) {
        insertionSort(arr);
        return;
    }
    int mid = n / 2;
    std::list<int> left;
    std::list<int>::iterator it = arr.begin();
    for (int i = 0; i < mid; i++) {
        left.push_back(*it);
        it++;
    }
    std::list<int> right;
    while (it != arr.end()) {
        right.push_back(*it);
        it++;
    }
    arr.clear();
    mergeInsertionSort(left, threshold);
    mergeInsertionSort(right, threshold);
    merge(arr, left, right);
}

void PmergeMe::mergeList()
{
    mergeInsertionSort(l, 10);
}

template<typename T>
bool    PmergeMe::contains(const T &container, int i)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
    {
        if (*it == i)
            return true;
    }
    return false;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{
}