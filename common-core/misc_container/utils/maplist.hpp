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
		typedef ft::const_map_iterator<Node, Compare> const_iterator;

		//---PUBLIC VARIABLE
		Node					*head;

		maplist(const allocator &alloc = allocator()) : head(NULL), alloc_node(alloc)
		{
			node_end = alloc_node.allocate(1);
			alloc_node.construct(node_end, Node());
			head = node_end;
		};

		~maplist()
		{

		};
		
		ft::pair<iterator, bool>	insertPair(pair_type i)
		{
			Node	*tmp = head;

			if (tmp == node_end)
			{
				tmp = alloc_node.allocate(1);
				alloc_node.construct(tmp, Node(i));
				head->prev = tmp;
				tmp->next = head;
				tmp->prev = NULL;
				head = tmp;
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
				return (ft::make_pair<iterator, bool>(iterator(tmp), true));
			}
			while (tmp->next != node_end && tmp->next->value.first <= i.first)
			{
				if (i.first == tmp->next->value.first)
					return (ft::make_pair<iterator, bool>(iterator(tmp), false));
				tmp = tmp->next;
			}
			if (tmp->next != node_end)
			{
				Node	*new_node;
				
				new_node = alloc_node.allocate(1);
				alloc_node.construct(new_node, Node(i));
				tmp->next->prev = new_node;
				new_node->next = tmp->next;
				new_node->prev = tmp;
				tmp->next = new_node;
			}
			else
			{
				tmp->next = alloc_node.allocate(1);
				alloc_node.construct(tmp->next, Node(i));
				tmp->next->prev = tmp;
				tmp->next->next = node_end;
				tmp->next->next->prev = tmp->next;
			}
			return (ft::make_pair<iterator, bool>(iterator(tmp), true));
		};

		Node	*get_last_node() const
		{
			return (node_end);	
		};

		Node	*get_last_node_reverse()
		{
			return (node_end);
		};

		int	size() const
		{
			Node	*tmp = head;
			int	i = 0;

			while (tmp != node_end)
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

			while (head != node_end)
			{
				tmp = head;
				head = head->next;
				alloc_node.destroy(tmp);
				alloc_node.deallocate(tmp, 1);
			};
		};

		void	destroy()
		{
			clear();
			alloc_node.destroy(head);
			alloc_node.deallocate(head, 1);
		};

		bool	erase(const key_type &key)
		{
			Node	*tmp = head;
			
			while (tmp != node_end && tmp->value.first != key)
			{
				tmp = tmp->next;
			}
			if (tmp != node_end)
			{
				if (tmp->prev)
				{
					tmp->prev->next = tmp->next;
				}

				if (!tmp->prev)
				{
					head = tmp->next;
				}
				else if (tmp->next)
					tmp->next->prev = tmp->prev;
				alloc_node.destroy(tmp);
				alloc_node.deallocate(tmp, 1);
				return (true);
			}
			return (false);
		};

		void	swap(maplist &x)
		{
			if (this == &x)
				return ;

			Node	*tmp_end = node_end;
			Node	*tmp = head;

			head = x.head;
			node_end = x.node_end;
			x.node_end = tmp_end;
			x.head = tmp;
		};

		Node	*find(const key_type &k)
		{
			Node	*tmp = head;

			while (tmp != node_end && tmp->value.first != k)
				tmp = tmp->next;
			return (tmp);
		};

		void	aff_list() const
		{
			Node	*tmp = head;
			int	i = 0;

			if (tmp == node_end)
				std::cout << "NO LIST !" << std::endl;
			while (tmp != node_end)
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

			while	(tmp != node_end)
			{	
				if (tmp->value.first > k)
					return (tmp);
				tmp = tmp->next;
			};
			return (tmp);
		};

		Node	*lower_bound(const key_type &k)
		{
			Node	*tmp = head;

			while (tmp != node_end)
			{
				if (tmp->value.first >= k)
					return (tmp);
				tmp = tmp->next;
			}
			return (tmp);
		};

		private :
		Node		*node_end;
		allocator	alloc_node;
	};
};

#endif
