#ifndef LIST_HPP
# define LIST_HPP

namespace ft
{
	template<typename T>
	struct	tree_node
	{
		typedef T	value_type;
		
		value_type	value;
		tree_node	*right;
		tree_node	*left;
		tree_node	*parent;
		bool		black;

		tree_node() : value(), right(NULL),
		 left(NULL), parent(NULL), black(1)
		{};

		tree_node(T lvalue) : value(lvalue), right(NULL),
		 left(NULL), parent(NULL), black(1)
		{};

		tree_node(const tree_node &cpy) : value(cpy.value), right(cpy.right),
		 left(cpy.left), parent(cpy.parent), black(cpy.black)
		{};

		~tree_node()
		{};

		tree_node	&operator=(const tree_node &cpy)
		{
			this->value = cpy.value;
			this->right = cpy.right;
			this->left = cpy.left;
		};
		
	};
}
#endif
