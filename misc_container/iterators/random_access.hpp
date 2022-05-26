#ifndef RANDOM_ACCESS_HPP
# define RANDOM_ACCESS_HPP

# include <iostream>
# include "iterator.hpp"
# include "iterators_tag.hpp"

namespace ft
{
template<typename T>
class	random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
{
	public :
		
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type	value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
		typedef T*	pointer;
		typedef T&	reference;

		random_access_iterator() : i(NULL) {};
		random_access_iterator(T *x) : i(x) {};
		random_access_iterator(const random_access_iterator &cpy) : i(cpy.i) {};
		~random_access_iterator() {};

		//---OPERATORS START
		//

		random_access_iterator	&operator=(const random_access_iterator &cpy)
		{
			if (cpy == *this)
				return (*this);
			this->i = cpy.i;
			return (*this);
		};
		random_access_iterator	&operator++() 
		{
			++i;
			return *this;
		}
		random_access_iterator	operator++(int)
		{
			random_access_iterator	tmp(*this);
			
			++i;
			return (tmp);
		}
		random_access_iterator	operator--()
		{	
			--i;
			return (*this);
		}
		random_access_iterator	operator--(int)
		{
			random_access_iterator	tmp(*this);
			
			--i;
			return (tmp);
		}
		random_access_iterator	operator+(difference_type n) const
		{
			return (i + n);
		};
		random_access_iterator	operator-(difference_type n) const
		{
			return (i - n);
		};
		reference	operator[](difference_type n)
		{
			return (*(i + n));
		};
		random_access_iterator	&operator+=(difference_type n)
		{
			i += n;
			return (*this);
		};
		random_access_iterator	&operator-=(difference_type n)
		{
			i -= n;
			return (*this);
		};
		reference	operator*() const{
			return (*i);
		};
		pointer		operator->(void)
		{
			return (i);
		}
	
		operator	random_access_iterator<const T>() const
		{
			return (random_access_iterator<const T>(this->i));
		};	
		//
		//---OPERATORS END

		//---GETTER
		pointer	base() const{return this->i;};
	
	private :
			T	*i;
};
	
	template<typename T>
	typename ft::random_access_iterator<T>::difference_type	
	operator-(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	};
	
	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type	
	operator-(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() - rhs.base());
	};


	template<typename T>
	bool	operator>(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	};

	
	template<typename T, typename U>
	bool 	operator>(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() > rhs.base());
	};


	template<typename T>
	bool	 operator>=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	};
	
	template<typename T, typename U>	
	bool	operator>=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() >= rhs.base());
	};


	template<typename T>
	bool 	operator<(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	};
	
	template<typename T, typename U>
	bool	operator<(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() < rhs.base());
	};


	template<typename T>
	bool	operator<=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	};

		
	template<typename T, typename U>
	bool	operator<=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() <= rhs.base());
	};


	template<typename T>
	bool	operator==(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs){
			return rhs.base() == lhs.base();
	};
		
	template<typename T, typename U>
	bool	operator==(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() == rhs.base());
	};


	template<typename T>
	bool	operator!=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs){
			return rhs.base() != lhs.base();
	};
	
	template<typename T, typename U>
	bool operator!=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() != rhs.base());
	};


	template<typename T>
	typename ft::random_access_iterator<T>	
	operator+(typename ft::random_access_iterator<T>::difference_type i, typename ft::random_access_iterator<T> rhs)
	{
		return (rhs + i);
	};
	
/*template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type	
	operator+(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs)
	{
		return (lhs.base() - rhs.base());
	};
*/

}
#endif
