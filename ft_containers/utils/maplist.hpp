#ifndef MAPLIST_HPP
# define MAPLIST_HPP

# include "list.hpp"
# include "less.hpp"
# include "pair.hpp"
# include "map_iterator.hpp"

namespace ft
{
	template<typename T, typename Compare = ft::less<T>,
		typename Node = ft::list_node<T>,
		typename allocator = std::allocator<Node> >
	struct	maplist
	{
		typedef T				pair_type;
		typedef typename pair_type::first_type	key_type;
		typedef typename pair_type::second_type	value_type;
		typedef ft::map_iterator<Node, Compare> iterator;

		//---PUBLIC VARIABLE
		Node					*head;

		maplist(const allocator &alloc = allocator()) : head(NULL), alloc_node(alloc)
		{};

		~maplist()
		{

		};
		
		ft::pair<iterator, bool>	insertPair(pair_type i)
		{
			Node	*tmp = head;

			if (!tmp)
			{
				head = alloc_node.allocate(1);
				alloc_node.construct(head, Node(i));
				aff_list();
				return (ft::make_pair<iterator, bool>(iterator(head), true));
			}
			if (i.first < tmp->value.first)
			{
				tmp = alloc_node.allocate(1);
				alloc_node.construct(tmp, Node(i));
				head->prev = tmp;
				tmp->next = head;
				tmp->prev = NULL;
				head = tmp;
				aff_list();
				return (ft::make_pair<iterator, bool>(iterator(tmp), true));
			}
			while (tmp->next && tmp->value.first <= i.first)
			{
				if (i.first == tmp->value.first)
					return (ft::make_pair<iterator, bool>(iterator(tmp), false));
				tmp = tmp->next;
			}
			tmp->next = alloc_node.allocate(1);
			alloc_node.construct(tmp->next, Node(i));
			tmp->next->prev = tmp;
			tmp->next->next = NULL;
			aff_list();
			return (ft::make_pair<iterator, bool>(iterator(tmp), true));
		};

		Node	*get_last_node()
		{
			Node	*tmp = head;
			
			while (tmp)
				tmp = tmp->next;
			return tmp;
		};

		Node	*get_last_node_reverse()
		{
			Node	*tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			return (tmp);
		};

		int	size() const
		{
			Node	*tmp = head;
			int	i = 0;

			while (tmp)
			{
				tmp = tmp->next;
				i++;
			}
			return (i);
		};

		int	max_size() const
		{
			return (alloc_node.max_size());
		};

		void	clear()
		{
			Node	*tmp;

			while (head)
			{
				tmp = head;
				head = head->next;
				alloc_node.destroy(tmp);
				alloc_node.deallocate(tmp, 1);
			};
		};

		bool	erase(const key_type &key)
		{
			Node	*tmp = head;

			while (tmp->value.first	!= key)
			{
				tmp = tmp->next;
			}
			if (tmp)
			{
				if (tmp->prev)
					tmp->prev->next = tmp->next;
				if (tmp->next)
					tmp->next->prev = tmp->prev;
				alloc_node.destroy(tmp);
				alloc_node.deallocate(tmp, 1);
				return (true);
			}
			return (false);
		};

		void	swap(maplist &x)
		{
			if (*this == x)
				return ;

			Node	*tmp = head;
			head = x.head;
			x.head = tmp;
		};

		Node	*find(const key_type &k)
		{
			Node	*tmp = head;

			while (tmp->value.first != k)
				tmp = tmp->next;
			return (tmp);
		};

		void	aff_list()
		{
			Node	*tmp = head;
			int	i = 0;

			if (!tmp)
				std::cout << "NO LIST !" << std::endl;
			while (tmp)
			{
				i++;
				std::cout << i << ") : key :  " << tmp->value.first;
				std::cout << " value : " <<  tmp->value.second  << std::endl;
				tmp = tmp->next;
			}
			std::cout << std::endl;
		}

		Node	*upper_bound(const key_type &k)
		{
			Node	*tmp = head;

			while	(tmp)
			{	
				if (tmp->value.first > k)
					return (tmp);
				tmp = tmp->next;
			};
			return (tmp);
		};

		Node	*lower_bound(const key_type &k)
		{
			Node	*tmp;

			while (tmp)
			{
				if (tmp->value.first >= k)
					return (tmp);
				tmp = tmp->next;
			}
			return (tmp);
		};

		private :
		allocator	alloc_node;
	};
};

#endif
