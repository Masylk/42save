#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class	Array
{
	public :
		Array();
		Array(unsigned int n);
		Array(Array const &cpy);
		~Array(){};

		Array	&operator=(Array const &rhf);
	private :
};

#endif