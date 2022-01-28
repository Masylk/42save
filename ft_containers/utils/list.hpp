#ifndef LIST_HPP
# define LIST_HPP

namespace ft
{
	template<typename T>
	struct	list_node
	{
		typedef T	value_type;
		value_type	value;
		list_node	*next;
		list_node	*prev;

		list_node() : value(NULL), next(NULL), prev(NULL)
		{};

		list_node(T lvalue) : value(lvalue), next(NULL), prev(NULL)
		{};

		list_node(const list_node &cpy) : value(cpy.value), next(cpy.next), prev(cpy.prev)
		{};

		~list_node()
		{};

		list_node	&operator=(const list_node &cpy)
		{
			this->value = cpy.value;
			this->next = cpy.next;
			this->prev = cpy.prev;
		};
		
	};
}
#endif
