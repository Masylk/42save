#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class	Array
{
	public :
		Array(): elems(new T[0]), _size(0){};
		Array(unsigned int n): elems(new T[n]), _size(n)
		{	
			unsigned int	i;

			i = 0;
			while (i < n)
				elems[i++] = T();
		};
		//copy
		Array<T>(Array const &cpy) : elems(new T(cpy.size())), _size(cpy.size())
		{
			int	i;

			i = 0;
			while (i < _size)
				elems[i] = cpy[i++];	
		};
		~Array(){ delete[] elems; };
		
		//getter
		unsigned int	size(void) { return _size; };
		
		//operators
		//assign
		Array<T>	&operator=(Array const &rhf)
		{
			if (elems)
				delete[] elems;
			elems = new T[rhf.size()];
			_size = rhf.size();
			
			int i = 0;
			while (i < _size)
				elems[i] = rhf[i++];
		};
		//access
		T	&operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::exception();
			else
				return (elems[i]);
		}
	private :
		T		*elems;
		unsigned int	_size;
};

#endif
