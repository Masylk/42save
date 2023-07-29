#ifndef REVERSE_HPP
# define REVERSE_HPP

# include <iostream>
# include "iterator.hpp"
# include "iterators_tag.hpp"

namespace ft
{
template<typename T>
class	reverse_iterator
{
	public :
	
		typedef	T	iterator_type;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<T>::value_type	value_type;
		typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T>::pointer	pointer;
		typedef typename ft::iterator_traits<T>::reference	reference;

		reverse_iterator() : i(NULL) {};
		reverse_iterator(iterator_type x) : i(x) {};
		
		template <typename Iterator>
		reverse_iterator(const reverse_iterator<Iterator> &cpy) : i(cpy.base()) 
		{};
		
		virtual ~reverse_iterator() {};

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
			this->i.operator--();
			return *this;
		}
		reverse_iterator	operator++(int)
		{
			return (reverse_iterator(this->i.operator--(0)));
		}
		reverse_iterator	operator--()
		{	
			this->i.operator++();
			return (*this);
		}
		reverse_iterator	operator--(int)
		{
			return (reverse_iterator(this->i.operator++(0)));
		}
		reverse_iterator	operator+(difference_type n) const
		{
			return (reverse_iterator(this->i.operator-(n)));
		};
		reverse_iterator	operator-(difference_type n) const
		{
			return (reverse_iterator(this->i.operator+(n)));
		};
		reference	operator[](difference_type n)
		{
			return (*this->operator+(n));
		};
		reverse_iterator	&operator+=(difference_type n)
		{
			this->i.operator-=(n);
			return (*this);
		};
		reverse_iterator	&operator-=(difference_type n)
		{
			this->i.operator+=(n);
			return (*this);
		};
		reference	operator*() const {
			return (--super(this->i)).operator*();
		};
		pointer		operator->(void) const
		{
			return (&this->operator*());
		}
		
		friend reverse_iterator	operator+(difference_type n, const reverse_iterator &rhs)
		{
			return (rhs.operator+(n));
		}
		//
		//---OPERATORS END

		//---GETTER
		iterator_type	base() const{return this->i;};
	
	protected :
			typedef T	super;
			iterator_type	i;
};
	
	template<typename T>
	typename ft::reverse_iterator<T>::difference_type	
	operator-(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs)
	{
		return (rhs.base() - lhs.base());
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

	//Const and non const operations
	
	template<typename T, typename U>
	typename ft::reverse_iterator<T>::difference_type	
	operator-(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<U> rhs)
	{
		return (rhs.base() - lhs.base());
	};

	template<typename T, typename U>
	bool	operator>(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<U> rhs)
	{
		return (lhs.base() < rhs.base());
	};


	template<typename T, typename U>
	bool	 operator>=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<U> rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template<typename T, typename U>
	bool 	operator<(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<U> rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template<typename T, typename U>
	bool	operator<=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<U> rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template<typename T, typename U>
	bool	operator==(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<U> rhs){
			return rhs.base() == lhs.base();
	};


	template<typename T, typename U>
	bool	operator!=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<U> rhs){
			return rhs.base() != lhs.base();
	};

	template<typename T, typename U>
	typename ft::reverse_iterator<T>	
	operator+(typename ft::reverse_iterator<T>::difference_type i, typename ft::reverse_iterator<U> rhs)
	{
		return (rhs + i);
	};
}
#endif
