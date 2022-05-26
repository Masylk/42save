#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include <iostream>
# include <limits>
# include <utility>
# include <cstddef>
# include <memory>
# include "less.hpp"
# include "maplist.hpp"
# include "reverse_map.hpp"
# include "template.hpp"
# include "equal.hpp"

namespace ft
{
	template<typename Key, typename T, typename Compare = less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public :

		//---MEMBER TYPES START
		//
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef pair<const key_type, mapped_type>				value_type;
		typedef Compare								key_compare;
		typedef Alloc								allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename ft::maplist<value_type, Compare>::iterator		iterator;
		typedef typename ft::maplist<value_type, Compare>::const_iterator	const_iterator;
		typedef ft::reverse_iterator_map<iterator>				reverse_iterator;
		typedef ft::reverse_iterator_map<const_iterator>			const_reverse_iterator;
		typedef ptrdiff_t							difference_type;
		typedef size_t								size_type;

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
			
			value_compare(Compare c) : comp(c) 
			{};
			
			bool	operator()(const value_type &x, const value_type &y) const
			{
				return (comp(x.first, y.first));
			};
			protected :

			Compare comp;
		};
		
		//
		//---NESTED CLASS END
	
		//---CONSTRUCTORS START
		//
		
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: compare(comp), allocator(alloc), container()
		{
		};

		template<class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		:
			compare(comp),
			allocator(alloc),
			container()
		{
			insert(first, last);
		};

		map(const map &x) : compare(x.compare), allocator(x.allocator), container()
		{
			insert(x.begin(), x.end());
		};
	
		~map()
		{
			container.destroy();
		};	
		//
		//---CONSTRUCTORS END
	
		//---ITERATORS START
		//
			iterator	begin()
			{
				return (iterator(container.head));
			};

			const_iterator	begin() const
			{
				return (const_iterator(container.head));
			};

			iterator	end()
			{
				return (iterator(container.get_last_node()));
			}
			
			const_iterator	end() const
			{
				return (const_iterator(container.get_last_node()));
			}

			reverse_iterator	rbegin()
			{
				return (reverse_iterator(container.get_last_node_reverse()));
			};
			
			const_reverse_iterator	rbegin() const
			{
				return (reverse_iterator(container.get_last_node_reverse()));
			};

			reverse_iterator	rend()
			{
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator	rend() const
			{
				return (reverse_iterator(begin()));
			};

		//
		//---ITERATORS END

		//---CAPACITY FUNCCTIONS START
		//
		
			bool	empty() const
			{
				if (container.head == container.get_last_node())
					return (true);
				return (false);
			};

			size_type	size() const
			{
				return (container.size());
			};

			size_type	max_size() const
			{
				return (container.max_size());
			};
		//
		//---CAPACITY FUNCTIONS END
		
		//---MODIFIERS FUNCTIONS START
		//
		
			void	clear()
			{
				container.clear();
			};

			void	erase(iterator position)
			{
				container.erase(position->first);
			};

			size_type	erase(const key_type &k)
			{
				if (container.erase(k))
					return (1);
				return (0);
			};

			void	erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first++);
				};
			};
			
			void	swap(map &x)
			{
				container.swap(x.container);
			};

			pair<iterator, bool>	insert(const value_type &val)
			{
				pair<iterator, bool>	res = container.insertPair(val);


				return (res);
			};

			iterator	insert(iterator position, const value_type &val)
			{
				(void)position;
				return (iterator(container.insertPair(val).first));
			};

			template<typename InputIterator>
			void	insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				while (first != last)
				{
					insert(*(first++));
				}
			};
		//
		//---MODIFIERS FUNCTIONS END
	
		//---OPERATIONS FUNCTIONS START
		//
			iterator	find(const key_type &k)
			{
				return (iterator(container.find(k)));
			};

			const_iterator	find(const key_type &k) const
			{
				return (const_iterator(container.find(k)));
			};
	
			size_type	count(const key_type &k) const
			{
				if (container.find(k) != container.get_last_node())
					return (1);
				return (0);
			};	
		
			iterator	lower_bound(const key_type &k)
			{
				return (iterator(container.lower_bound(k)));
			};

			const_iterator	lower_bound(const key_type &k) const
			{
				const_iterator	it = container.lower_bound(k);
				return (it);
			};

			iterator	upper_bound(const key_type &k)
			{
				return (iterator(container.upper_bound(k)));
			};

			const_iterator	upper_bound(const key_type &k) const
			{
				return (const_iterator(container.upper_bound(k)));
			};

			ft::pair<iterator, iterator>	equal_range(const key_type &k)
			{
				return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			};	

			ft::pair<const_iterator, const_iterator>	equal_range(const key_type &k) const
			{
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			};
		//
		//---OPERATIONS FUNCTIONS END	
	
		//---OBSERVERS FUNCTIONS START
		//
			
			key_compare	key_comp() const
			{
				return (key_compare());
			};

			value_compare	value_comp() const
			{
				return (value_compare(key_compare()));
			};
			
			allocator_type	get_allocator() const
			{
				return (allocator);
			};	
		//
		//---OBSERVERS FUNCTIONS END

		mapped_type	&operator[](const key_type &k)
		{
			return ((find(k))->second);
		};

		map	&operator=(const map &cpy)
		{
			if (this == &cpy)
				return (*this);
			clear();
			insert(cpy.begin(), cpy.end());
			return (*this);
		};

		private:

		key_compare			compare;
		allocator_type			allocator;
		maplist<value_type, Compare>	container;
	};

	//---RELATIONAL-OPERATORS---
	//
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc> &lhs,
			const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.end()));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs,
			const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc> &lhs,
			const map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end()));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc> &lhs,
			const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc> &lhs,
			const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs,
			const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	//
	//--------------------------




};



#endif
