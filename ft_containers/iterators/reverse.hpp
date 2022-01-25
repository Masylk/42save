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
		reference	operator*(){
			iterator_type	tmp = i;
			return (*(--tmp));
		};
		pointer		operator->(void) const
		{
			return (i);
		}
		
		//
		//---OPERATORS END

		//---GETTER
		iterator_type	base() const{return this->i;};
	
	private :
			iterator_type	i;
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
