#ifndef REVERSE_HPP
# define REVERSE_HPP

# include <iostream>
# include "iterator.hpp"
# include "iterators_tag.hpp"

namespace ft
{
template<typename T>
class	reverse_iterator : public ft::iterator<ft::random_access_iterator_tag, int>
{
	public :
		
		reverse_iterator() : i(NULL) {};
		reverse_iterator(T *x) : i(x) {};
		reverse_iterator(const reverse_iterator &cpy) : i(cpy.i) {};
		~reverse_iterator() {};

		//---OPERATORS START
		//

		reverse_iterator	&operator=(const reverse_iterator &cpy)
		{
			if (cpy == *this)
				return (*this);
			this->i = cpy.i;
			return (*this);
		};
		reverse_iterator	&operator++() 
		{
			--i;
			return *this;
		}
		reverse_iterator	operator++(int)
		{
			reverse_iterator	tmp(*this);
			
			--i;
			return (tmp);
		}
		reverse_iterator	operator--()
		{	
			++i;
			return (*this);
		}
		reverse_iterator	operator--(int)
		{
			reverse_iterator	tmp(*this);
			
			++i;
			return (tmp);
		}
		reverse_iterator	operator+(difference_type n) const
		{
			return (i - n);
		};
		reference	operator[](difference_type n)
		{
			return (*(i - n));
		};
		reverse_iterator	&operator+=(difference_type n)
		{
			i -= n;
			return (*this);
		};
		reverse_iterator	&operator-=(difference_type n)
		{
			i += n;
			return (*this);
		};
		int		&operator*(){
			return (*(i - 1));
		};
		pointer		operator->(void)
		{
			return (i);
		}
		
		//
		//---OPERATORS END

		//---GETTER
		pointer	base() const{return this->i;};
	
	private :
			T	*i;
};
	
	template<typename T>
	typename ft::reverse_iterator<T>::difference_type	
	operator-(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	};

	template<typename T>
	bool	operator>(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	};


	template<typename T>
	bool	 operator>=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template<typename T>
	bool 	operator<(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template<typename T>
	bool	operator<=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	
	template<typename T>
	bool	operator==(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){
			return rhs.base() == lhs.base();
	};
	
	template<typename T>
	bool	operator!=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){
			return rhs.base() != lhs.base();
	};

	template<typename T>
	typename ft::reverse_iterator<T>	
	operator+(typename ft::reverse_iterator<T>::difference_type i, typename ft::reverse_iterator<T> rhs)
	{
		return (rhs + i);
	};

}
#endif
