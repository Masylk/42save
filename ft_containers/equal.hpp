#ifndef EQUAL_HPP
# define EQUAL_HPP

# include "pair.hpp"

namespace ft
{
template<typename T, typename T1>
bool	equal(T first, T last, T1 first1)
{
	while (first != last)
	{
		if (*first != *first1)
			return false;
		first++;
		first1++;
	}
	return true;
}

template<typename T, typename T1>
bool	lexicographical_compare(T first, T last, T1 first1, T1 last1)
{
	while (first != last && first1 != last1 && *first == *first1)
	{
		first++;
		first1++;
	}
	if (first == last)
		return (first1 != last1);
	else if (first1 == last1)
		return (false);
	return (*first < *first1);
}

};
#endif
