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
		Node					*head;
		typedef ft::map_iterator<Node, Compare> iterator;

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
		private :
		allocator	alloc_node;
	};
};

#endif
