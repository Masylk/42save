#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include <cstddef>
# include <typeinfo>

//# include "random_access.hpp"

namespace ft
{
template<typename Category, typename T, typename Distance = ptrdiff_t,
	typename Pointer = T*, typename Reference = T&>
	class iterator
	{
		public:
		typedef T		value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

template<typename IteratorT>
	class	iterator_traits
	{
		public:
		typedef typename IteratorT::value_type		value_type;
		typedef typename IteratorT::pointer		pointer;
		typedef typename IteratorT::reference		reference;
		typedef typename IteratorT::iterator_category	iterator_category;
		typedef typename IteratorT::difference_type	difference_type;	
	};

template<typename T>
	class	iterator_traits<T*>
	{
		public:
		typedef T					value_type;
		typedef T*					pointer;
		typedef T&					reference;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef ptrdiff_t				difference_type;
	};

template<typename IteratorT>
	bool	isIterator()
	{
		typedef ft::iterator_traits<IteratorT>	traits;

		if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
			return true;
		return false;
	};

	template<typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last)
	{
		return (last - first);
	};

}

#endif
