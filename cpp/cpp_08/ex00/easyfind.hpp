#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
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
	typename T::const_iterator	it;

	tmp = const_cast<T&>(list);
	it = tmp.begin();
	while (it != tmp.end())
	{
		if (*it == i)
			return (*it);
		it++;
	}
	throw NotFoundException();
}
#endif 
