#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include <iostream>
# include "reverse.hpp"
# include "less.hpp"
# include "maplist.hpp"

namespace ft
{
	template<typename Key, typename T, typename Compare = less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public :

		//---MEMBER TYPES START
		//
		typedef Key							key_type;
		typedef T							mapped_type;
		typedef pair<const key_type, mapped_type>			value_type;
		typedef Compare							key_compare;
		typedef Alloc							allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::maplist<value_type, Compare>::iterator	iterator;
		typedef const iterator						const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef const reverse_iterator					const_reverse_iterator;
		typedef ptrdiff_t						difference_type;
		typedef size_t							size_type;

		//
		//---MEMBER TYPES END

		//---NESTED CLASS START
		//
		
		class	value_compare
		{
			public :

			typedef bool		result_type;
			typedef value_type	first_type;
			typedef value_type	second_type;
			
			bool	operator()(const value_type &x, const value_type &y) const
			{
				return (comp(x.first, y.first));
			};
			protected :

			Compare comp;
			value_compare(Compare c) : comp(c) 
			{};
		};
		
		//
		//---NESTED CLASS END
	
		//---CONSTRUCTORS START
		//
		
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: compare(comp), allocator(alloc), container()
		{
			this->container.insertPair(make_pair<int, int>(6, 3));
			this->container.insertPair(make_pair<int, int>(7, 2));
			this->container.insertPair(make_pair<int, int>(5, 4));
		};

		template<class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		:
			compare(comp),
			allocator(alloc)
		{
			//insert(first, last);
		};

		map(const map &x) : compare(x.compare), allocator(x.allocator)
		{};
		
		//
		//---CONSTRUCTORS END
	
		private:

		key_compare			compare;
		allocator_type			allocator;
		maplist<value_type, Compare>	container;
	};
};

#endif
