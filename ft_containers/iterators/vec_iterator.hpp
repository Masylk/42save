#ifndef VEC_ITERATOR_HPP
# define VEC_ITERATOR_HPP

# include <iostream>
# include "iterator.hpp"
# include "iterators_tag.hpp"

//TODO
//recoder std::iterator
namespace ft
{
template<typename T>
class	IteratorVec : public ft::iterator<ft::random_access_iterator_tag, int>
{
	public :
		
		IteratorVec() : i(NULL) {};
		IteratorVec(T *x) : i(x) {};
		IteratorVec(const IteratorVec &cpy) : i(cpy.i) {};
		~IteratorVec() {};

		//---OPERATORS START
		//

		IteratorVec	&operator=(const IteratorVec &cpy)
		{
			if (cpy == *this)
				return (*this);
			this->i = cpy.i;
			return (*this);
		};
		IteratorVec	&operator++() 
		{
			++i;
			return *this;
		}
		IteratorVec	operator++(int)
		{
			IteratorVec	tmp(*this);
			
			++i;
			return (tmp);
		}
		IteratorVec	operator--()
		{	
			++i;
			return (*this);
		}
		IteratorVec	operator--(int)
		{
			IteratorVec	tmp(*this);
			
			++i;
			return (tmp);
		}
		IteratorVec	operator+(difference_type n) const
		{
			return (i + n);
		};
		reference	operator[](difference_type n)
		{
			return (*(i + n));
		};
		IteratorVec	&operator+=(difference_type n)
		{
			i += n;
			return (*this);
		};
		IteratorVec	&operator-=(difference_type n)
		{
			i -= n;
			return (*this);
		};
		int		&operator*(){
			return (*i);
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
	typename ft::IteratorVec<T>::difference_type	
	operator-(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs)
	{
		return (lhs.base() - rhs.base());
	};

	template<typename T>
	bool	operator>(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs)
	{
		return (lhs.base() > rhs.base());
	};


	template<typename T>
	bool	 operator>=(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template<typename T>
	bool 	operator<(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template<typename T>
	bool	operator<=(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	
	template<typename T>
	bool	operator==(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs){
			return rhs.base() == lhs.base();
	};
	
	template<typename T>
	bool	operator!=(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs){
			return rhs.base() != lhs.base();
	};

	template<typename T>
	typename ft::IteratorVec<T>::difference_type	
	operator+(typename ft::IteratorVec<T>::difference_type i, typename ft::IteratorVec<T> rhs)
	{
		return (&(*rhs) + i);
	};

}
#endif
