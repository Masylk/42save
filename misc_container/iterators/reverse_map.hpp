#ifndef REVERSE_MAP_HPP
# define REVERSE_MAP_HPP

# include <iostream>
# include "iterator.hpp"
# include "iterators_tag.hpp"

namespace ft
{
template<typename T>
class	reverse_iterator_map
{
	public :
	
		typedef	T	iterator_type;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<T>::value_type	value_type;
		typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T>::pointer	pointer;
		typedef typename ft::iterator_traits<T>::reference	reference;

		reverse_iterator_map() : i(NULL) {};
		reverse_iterator_map(iterator_type x) : i(x) {};
		
		template <typename Iterator>
		reverse_iterator_map(const reverse_iterator_map<Iterator> &cpy) : i(cpy.base()) 
		{};
		
		virtual ~reverse_iterator_map() {};

		//---OPERATORS START
		//

		reverse_iterator_map	&operator=(const reverse_iterator_map &cpy)
		{
			if (cpy == *this)
				return (*this);
			this->i = cpy.i;
			return (*this);
		};
		reverse_iterator_map	&operator++() 
		{
			--i;
			return *this;
		}
		reverse_iterator_map	operator++(int)
		{
			reverse_iterator_map	tmp(*this);
			
			--(*this);
			return (tmp);
		}
		reverse_iterator_map	&operator--()
		{	
			++i;
			return (*this);
		}
		reverse_iterator_map	operator--(int)
		{
			reverse_iterator_map	tmp(*this);
			
			++(*this);
			return (tmp);
		}
		reverse_iterator_map	operator+(difference_type n) const
		{
			return (i - n);
		};
		reference	operator[](difference_type n)
		{
			return (*(i - n));
		};
		reverse_iterator_map	&operator+=(difference_type n)
		{
			i -= n;
			return (*this);
		};
		reverse_iterator_map	&operator-=(difference_type n)
		{
			i += n;
			return (*this);
		};
		reference	operator*() const {
			iterator_type	tmp = i;	
			return (*(--tmp));
		};
		pointer		operator->(void) const
		{
			return (&(operator*()));
		}
		
		//
		//---OPERATORS END

		//---GETTER
		iterator_type	base() const{return this->i;};
	
	private :
			iterator_type	i;
};
	
	template<typename T>
	typename ft::reverse_iterator_map<T>::difference_type	
	operator-(const ft::reverse_iterator_map<T> lhs, const ft::reverse_iterator_map<T> rhs)
	{
		return (lhs.base() - rhs.base());
	};

	template<typename T>
	bool	operator>(const ft::reverse_iterator_map<T> lhs, const ft::reverse_iterator_map<T> rhs)
	{
		return (lhs.base() < rhs.base());
	};


	template<typename T>
	bool	 operator>=(const ft::reverse_iterator_map<T> lhs, const ft::reverse_iterator_map<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template<typename T>
	bool 	operator<(const ft::reverse_iterator_map<T> lhs, const ft::reverse_iterator_map<T> rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template<typename T>
	bool	operator<=(const ft::reverse_iterator_map<T> lhs, const ft::reverse_iterator_map<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	
	template<typename T>
	bool	operator==(const ft::reverse_iterator_map<T> lhs, const ft::reverse_iterator_map<T> rhs){
			return rhs.base() == lhs.base();
	};
	
	template<typename T>
	bool	operator!=(const ft::reverse_iterator_map<T> lhs, const ft::reverse_iterator_map<T> rhs){
			return rhs.base() != lhs.base();
	};

	template<typename T>
	typename ft::reverse_iterator_map<T>	
	operator+(typename ft::reverse_iterator_map<T>::difference_type i, typename ft::reverse_iterator_map<T> rhs)
	{
		return (rhs + i);
	};

}
#endif
