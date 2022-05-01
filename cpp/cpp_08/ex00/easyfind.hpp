#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>

class	NotFoundException : public std::exception
{
	public :
		virtual const char	*what() const throw()
		{
			return ("Occurence not found");
		}
};

template<typename T>
int	easyfind(const T&list, const int i)
{
	T		tmp;
	typename T::iterator	it;

	tmp = const_cast<T&>(list);
/*	it = tmp.begin();
	while (it != tmp.end())
	{
		if (*it == i)
			return (*it);
		it++;
	}*/
	it = std::find(tmp.begin(), tmp.end(), i);
	if (it == tmp.end())
		throw NotFoundException();
	else
		return *it;
}
#endif 
