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
			return *this;
		}
		IteratorVec	operator--(int)
		{
			IteratorVec	tmp(*this);
			
			++i;
			return (tmp);
		}

		bool	operator==(const IteratorVec &rhs) const{
			return rhs.i == i;
		};
		bool	operator!=(const IteratorVec &rhs) const{
			return rhs.i != i;
		};
		int		&operator*(){
			return *i;
		};

		pointer	base() const{return this->i;};
	private :
			T	*i;
};
	
	template<typename T>
	typename ft::IteratorVec<T>::difference_type	
	operator-(const ft::IteratorVec<T> lhs, const ft::IteratorVec<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}

}
#endif
