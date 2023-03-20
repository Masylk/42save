#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <stack>
#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <iomanip>

using namespace std;

template<typename T>
void vectorMemberFunctionExample(T &v) {

    // add elements to the vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // get the size of the vector
    std::cout << "Size of vector: " << v.size() << std::endl;

    // get the maximum number of elements that the vector can hold
    std::cout << "Maximum size of vector: " << v.max_size() << std::endl;

    // get the capacity of the vector
    std::cout << "Capacity of vector: " << v.capacity() << std::endl;

    // check if the vector is empty
    if (v.empty()) {
        std::cout << "Vector is empty" << std::endl;
    } else {
        std::cout << "Vector is not empty" << std::endl;
    }

    // get the first element of the vector
    std::cout << "First element of vector: " << v.front() << std::endl;

    // get the last element of the vector
    std::cout << "Last element of vector: " << v.back() << std::endl;

    // resize the vector
    v.resize(5);

    // get the new size of the vector
    std::cout << "New size of vector after resize: " << v.size() << std::endl;

    // access elements of the vector using the [] operator
    for (size_t i = 0; i < v.size(); i++) {
        v[i] = i + 1;
    }

    // access elements of the vector using iterators
    for (typename T::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // clear the vector
    v.clear();

    // check if the vector is empty again
    if (v.empty()) {
        std::cout << "Vector is empty" << std::endl;
    } else {
        std::cout << "Vector is not empty" << std::endl;
    }
	std::cout << std::endl;
}

template<typename T>
void mapMemberFunctions_ft(T &m) {
   	clock_t start;
   	clock_t end;
	double timeTaken;

    // insert elements into the map
	start = clock();
   

  
    m.insert(ft::make_pair("one", 1));
    m.insert(ft::make_pair("two", 2));
    m.insert(ft::make_pair("three", 3));
   
    end = clock();	
	timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken by function insert: " << std::fixed << std::setprecision(8) << timeTaken << " seconds" << endl;

    // get the size of the map
    std::cout << "Size of map: " << m.size() << std::endl;

    // check if the map is empty
    if (m.empty()) {
        std::cout << "Map is empty" << std::endl;
    } else {
        std::cout << "Map is not empty" << std::endl;
    }

    // access elements of the map using the [] operator
    std::cout << "Value of key 'one': " << m["one"] << std::endl;

    // access elements of the map using iterators
    for (typename T::iterator it = m.begin(); it != m.end(); it++) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

  	start = clock();
    // erase an element from the map
    m.erase("two");
    end = clock();

    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken by function erase: " << timeTaken << " seconds" << endl;

    // get the new size of the map
    std::cout << "New size of map after erasing an element: " << m.size() << std::endl;

    // create a copy of the map
    T	m2 = m;

    // swap the contents of two maps
    T 	m3;
    m3["four"] = 4;
    m3["five"] = 5;
    m.swap(m3);

    // get the size of the swapped map
    std::cout << "Size of swapped map: " << m.size() << std::endl;

    // check if the copy of the map is equal to the original map
    if (m2 == m) {
        std::cout << "Copied map is equal to original map" << std::endl;
    } else {
        std::cout << "Copied map is not equal to original map" << std::endl;
    }
	std::cout << std::endl;
}


template<typename T>
void mapMemberFunctions_std(T &m) {
   	clock_t start;
   	clock_t end;
	double timeTaken;

    // insert elements into the map
	start = clock();
   

  
    m.insert(std::make_pair("one", 1));
    m.insert(std::make_pair("two", 2));
    m.insert(std::make_pair("three", 3));
   
    end = clock();	
	timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken by function insert: " << std::fixed << std::setprecision(8) << timeTaken << " seconds" << endl;

    // get the size of the map
    std::cout << "Size of map: " << m.size() << std::endl;

    // check if the map is empty
    if (m.empty()) {
        std::cout << "Map is empty" << std::endl;
    } else {
        std::cout << "Map is not empty" << std::endl;
    }

    // access elements of the map using the [] operator
    std::cout << "Value of key 'one': " << m["one"] << std::endl;

    // access elements of the map using iterators
    for (typename T::iterator it = m.begin(); it != m.end(); it++) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

   	start = clock();
    // erase an element from the map
    m.erase("two");
    end = clock();

    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken by function erase: " << std::fixed << std::setprecision(8) << timeTaken << " seconds" << endl;

    // get the new size of the map
    std::cout << "New size of map after erasing an element: " << m.size() << std::endl;

    // create a copy of the map
    T	m2 = m;

    // swap the contents of two maps
    T 	m3;
    m3["four"] = 4;
    m3["five"] = 5;
    m.swap(m3);

    // get the size of the swapped map
    std::cout << "Size of swapped map: " << m.size() << std::endl;

    // check if the copy of the map is equal to the original map
    if (m2 == m) {
        std::cout << "Copied map is equal to original map" << std::endl;
    } else {
        std::cout << "Copied map is not equal to original map" << std::endl;
    }
	std::cout << std::endl;
}


template<typename T>
void stackMemberFunctionExample(T &s) {
    // create an empty stack

    // push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);

    // get the size of the stack
    std::cout << "Size of stack: " << s.size() << std::endl;

    // check if the stack is empty
    if (s.empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    // get the top element of the stack
    std::cout << "Top element of stack: " << s.top() << std::endl;

    // pop elements from the stack
    s.pop();
    s.pop();

    // get the new size of the stack
    std::cout << "New size of stack after popping elements: " << s.size() << std::endl;

    // push more elements onto the stack
    s.push(4);
    s.push(5);
    s.push(6);

    // get the new top element of the stack
    std::cout << "New top element of stack: " << s.top() << std::endl;

    // create a copy of the stack
    T s2 = s;

    // check if the copy of the stack is equal to the original stack
    if (s2 == s) {
        std::cout << "Copied stack is equal to original stack" << std::endl;
    } else {
        std::cout << "Copied stack is not equal to original stack" << std::endl;
    }
	std::cout << std::endl;
}

int main()
{
	std::vector<int> std_v;
	ft::vector<int> ft_v;
	ft::stack<int, std::list<int> > ft_s;
	std::stack<int, std::list<int> > std_s;
	std::map<std::string, int>		std_m;
	ft::map<std::string, int>		ft_m;

	std::cout << "std::vector" << std::endl;
	vectorMemberFunctionExample(std_v);
	std::cout << "ft::vector" << std::endl;
	vectorMemberFunctionExample(ft_v);
	std::cout << "std::stack" << std::endl;
	stackMemberFunctionExample(std_s);
	std::cout << "ft::stack" << std::endl;
	stackMemberFunctionExample(ft_s);
	std::cout << "std::map" << std::endl;
	mapMemberFunctions_std(std_m);
	std::cout << "ft::map" << std::endl;
	mapMemberFunctions_ft(ft_m);

    // test_vector();
    // std::std::cout << "\n";
    // test_list();
    // std::std::cout << "\n";
    // test_map();
    // std::std::cout << "\n";
    // test_deque();
    // std::std::cout << "\n";
    // test_stack();
    // std::std::cout << "\n";
    // test_queue();
}