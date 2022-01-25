#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iostream>
# include "iterator.hpp"
# include "iterators_tag.hpp"

namespace ft
{
template<typename T, typename Comp>
class	map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, int>
{
	public :
		
		typedef typename T::value_type									value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer		pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference		reference;

		map_iterator(const Comp &cmp = Comp()) : i(NULL), comp(cmp) {};
		map_iterator(T *x, const Comp &cmp = Comp()) : i(x), comp(cmp) {};
		map_iterator(const map_iterator &cpy) : i(cpy.i), comp(cpy.comp) {};
		~map_iterator() {};

		//---OPERATORS START
		//

		map_iterator	&operator=(const map_iterator &cpy)
		{
			if (cpy == *this)
				return (*this);
			this->i = cpy.i;
			this->comp = cpy.comp;
			return (*this);
		};
		map_iterator	&operator++() 
		{
			i = i->next;
			return *this;
		}
		map_iterator	operator++(int)
		{
			map_iterator	tmp(*this);
			
			i = i->next;
			return (tmp);
		}
		map_iterator	operator--()
		{	
			i = i->prev;
			return (*this);
		}
		map_iterator	operator--(int)
		{
			map_iterator	tmp(*this);
			
			i = i->prev;
			return (tmp);
		}
		reference	operator*() const{
			return (i->value);
		};
		pointer		operator->(void)
		{
			return (&(i->value));
		}
		
		//
		//---OPERATORS END

		//---GETTER
		pointer	base() const{return this->i;};
	
	private :
			T	*i;
			Comp	comp;
};
	template<typename T, typename Compare>
	bool	operator==(const ft::map_iterator<T, Compare> lhs, const ft::map_iterator<T, Compare> rhs){
			return rhs.base() == lhs.base();
	};
	
	template<typename T, typename Compare>
	bool	operator!=(const ft::map_iterator<T, Compare> lhs, const ft::map_iterator<T, Compare> rhs){
			return rhs.base() != lhs.base();
	};
}
#endif
