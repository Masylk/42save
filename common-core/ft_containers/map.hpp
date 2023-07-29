#ifndef MAP_HPP
# define MAP_HPP

# include "template.hpp"
# include "reverse_iterator_map.hpp"
# include "algorithm.hpp"
# include "map_utils.hpp"
# include "less.hpp"


#define  RED true
#define BLACK false

namespace ft
{


template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
class map {
public:

	//////////////////////////////
	// Node
	//////////////////////////////

	typedef struct				s_node
	{
		ft::pair<const Key, T>	data;
		struct s_node *			left;
		struct s_node *			right;
		struct s_node *			parent;
		bool					color;

		s_node (ft::pair<const Key, T> data) : data(data) {};
		const Key	&key(void)	
		{ 
			return (data.first);
		};
		
		T 	&val(void)
		{ 
			return (data.second); 
		};
	}							Node;

	//////////////////////////////
	// Iterator subclass
	//////////////////////////////

	template <bool IsConst>
	class iterator_map {
	public:
		// Member types
		typedef					ft::pair<const Key, T>										pair_type;
		typedef typename		ft::conditional<IsConst, const pair_type, pair_type>::type	value_type;
		typedef typename		ft::conditional<IsConst, const Node, Node>::type			node_type;
		typedef					std::ptrdiff_t												difference_type;
		typedef					std::size_t													size_type;

		iterator_map(void)
		{
			i = NULL;
		};

		iterator_map(node_type *const x)
		{ 
			i = x; 
		};
		
		~iterator_map(void){}
		
		template <bool B>
		iterator_map(const iterator_map<B> &rhs, typename ft::enable_if<!B>::type* = 0)
		{ 
			i = rhs.getPos(); 
		};

		// Assignment
		iterator_map &			operator=(const iterator_map &rhs)
		{ 
			i = rhs.getPos();
			return (*this); 
		};

		// Comparison
		template <bool B> bool	operator==	(const iterator_map<B> &rhs) const
		{ 
			return (i == rhs.getPos());
		};

		template <bool B> bool	operator!=(const iterator_map<B> &rhs) const
		{ 
			return (i != rhs.getPos());
		};

		iterator_map			&operator++(void)
		{
			this->nextNode();
			return (*this);
		};

		iterator_map			operator++(int)
		{ 
			iterator_map<IsConst> tmp(*this);
			this->nextNode();
			return (tmp); 
		};
		
		iterator_map			&operator--	(void)
		{ 
			this->prevNode(); 
			return (*this); 
		};
		
		iterator_map			operator--(int)	
		{ 
			iterator_map<IsConst> x(*this); 
			this->prevNode(); return (x); 
		};

		value_type 				&operator*(void) const									
		{ 
			return (i->data); 
		};

		value_type *			operator->(void) const		
		{ 
			return (&i->data);
		};

		node_type *				getPos(void) const									
		{ 
			return (i);
		};

	private:
		node_type *i;

		void nextNode (void)
		{
			if (i->right != i->right->left)
			{
				i = i->right;
				while (i->left != i->left->left)
					i = i->left;
			}
			else
			{
				while (i == i->parent->right && i != i->parent)
					i = i->parent;
				i = i->parent;
			}
		}

		void prevNode (void)
		{
			if (i == i->parent)
			{
				while (i->right != i->right->left)
					i = i->right;
			}
			else if (i->left != i->left->left)
			{
				i = i->left;
				while (i->right != i->right->left)
					i = i->right;
			}
			else
			{
				while (i == i->parent->left && i != i->parent)
					i = i->parent;
				i = i->parent;
			}
		}
	};

	typedef		Key												key_type;
	typedef		T												mapped_type;
	typedef		ft::pair<const key_type, mapped_type>			value_type;
	
	class ValueCompare {
	public:
		friend			class			map;
		typedef			bool			result_type;
		typedef			value_type		first_argument_type;
		typedef			value_type		second_argument_type;
		bool			operator()		(const value_type &x, const value_type &y) const
		{ 
			return (comp(x.first, y.first)); 
		};
	protected:
		ValueCompare	(Compare c)		: comp(c){};
		Compare			comp;
	};

	typedef		Compare											key_compare;
	typedef		ValueCompare									value_compare;
	typedef		typename Alloc::template rebind<Node>::other	allocator_type;
	
	typedef		iterator_map<false>								iterator;
	typedef		iterator_map<true>								const_iterator;
	typedef		ft::reverse_iterator_map<iterator>				reverse_iterator;
	typedef		ft::reverse_iterator_map<const_iterator>		const_reverse_iterator;
	typedef		typename iterator_map<false>::difference_type	difference_type;
	typedef		typename iterator_map<false>::size_type			size_type;

	typedef		typename allocator_type::reference				reference;
	typedef		typename allocator_type::const_reference		const_reference;
	typedef		typename allocator_type::pointer				pointer;
	typedef		typename allocator_type::const_pointer			const_pointer;
	
	

	//---------------------- CONSTRUCTORS -----------------------------

	explicit map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
	{
		_alloc = alloc;
		_comp = comp;
		this->_null_node_create();
	};

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(),
	typename ft::enable_if<!ft::is_same<InputIterator, int>::value>::type* = 0)
	{
		_alloc = alloc;
		_comp = comp;
		this->_null_node_create();

		while (first != last)
			this->insert(*first++);
	};

	map (const map &x)
	{
		this->_null_node_create();
		*this = x;
	};

	~map(void)
	{
		this->clear();
		_alloc.destroy( TNULL);
		_alloc.deallocate( TNULL, 1);
	};

	map &operator=(const map &x)
	{
		if (this == &x)
			return (*this);

		this->clear();
		_alloc = x._alloc;
		_comp = x._comp;

		for (const_iterator it = x.begin() ; it != x.end() ; it++)
			this->insert(*it);
		return (*this);
	};

	iterator begin(void)
	{
		return (iterator(this->_minimum( TNULL->right)));
	};

	const_iterator begin(void) const
	{
		return (const_iterator(this->_minimum( TNULL->right)));
	};

	iterator end(void)
	{
		return (iterator( TNULL));
	};

	const_iterator end(void) const
	{
		return (const_iterator( TNULL));
	};

	reverse_iterator rbegin(void)
	{
		return (reverse_iterator( TNULL));
	};

	const_reverse_iterator rbegin(void) const
	{
		return (const_reverse_iterator( TNULL));
	};

	reverse_iterator rend(void)
	{
		return (reverse_iterator(this->_minimum( TNULL->right)));
	};

	const_reverse_iterator rend(void) const
	{
		return (const_reverse_iterator(this->_minimum( TNULL->right)));
	};

	bool empty(void) const
	{
		return ( TNULL ==  TNULL->right);
	};

	size_type size(void) const
	{
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
			n++;
		return (n);
	};

	size_type max_size(void) const
	{
		return (_alloc.max_size());
	};

	mapped_type &operator[](const key_type &k)
	{
		this->insert(ft::make_pair(k, mapped_type()));
		return (this->find(k)->second);
	};

	ft::pair<iterator,bool> insert(const value_type &val)
	{
		iterator it;
		if (this->count(val.first))
		{
			it = this->find(val.first);
			return (ft::make_pair(it, false));
		}
		else
		{
			it = iterator(this->_new_node(val));
			return (ft::make_pair(it, true));
		}
	};

	iterator insert(iterator position, const value_type &val)
	{
		(void)position;
		return (this->insert(val).first);
	};

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_same<InputIterator, int>::value>::type* = 0)
	{
		while (first != last)
			this->insert(*first++);
	};

	void erase(iterator position)
	{
		Node *x = position.getPos();

		if (x->left !=  TNULL && x->right !=  TNULL)
		{
			position--;
			this->_node_swap(x, position.getPos());
			this->erase(x);
		}
		else
		{
			Node *child = (x->left !=  TNULL) ? x->left : x->right;

			if (child !=  TNULL)
				child->parent = x->parent;
			if (x->parent->left == x)
				x->parent->left = child;
			else
				x->parent->right = child;

			this->_deleteNode(x, child);
		}
	};

	size_type erase(const key_type &k)
	{
		if (this->count(k))
		{
			this->erase(this->find(k));
			return (1);
		}
		return (0);
	};

	void erase(iterator first, iterator last)
	{
		for (iterator it = first++ ; it != last ; it = first++)
			this->erase(it);
	};

	void swap(map &x)
	{
		ft::swap(_alloc, x._alloc);
		ft::swap(_comp, x._comp);
		ft::swap( TNULL, x. TNULL);
	};

	void clear(void)
	{
		iterator first = this->begin();
		for (iterator it = first++ ; it != this->end() ; it = first++)
			this->erase(it);
	};

	key_compare key_comp(void) const
	{
		return (key_compare());
	};

	value_compare value_comp(void) const
	{
		return (value_compare(_comp));
	};

	iterator find(const key_type &k)
	{
		if (this->count(k))
			return (iterator(this->_findNode( TNULL->right, k)));
		else
			return (this->end());
	};

	const_iterator find(const key_type &k) const
	{
		if (this->count(k))
			return (const_iterator(this->_findNode( TNULL->right, k)));
		else
			return (this->end());
	};

	size_type count(const key_type &k) const
	{
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
		{
			if (this->_equal(k, it->first))
				n++;
		}
		return (n);
	};

	iterator lower_bound(const key_type &k)
	{
		iterator it = this->begin();
		while (this->_comp(it->first, k) && it != this->end())
			it++;
		return (it);
	};

	const_iterator lower_bound(const key_type &k) const
	{
		const_iterator it = this->begin();
		while (this->_comp(it->first, k) && it != this->end())
			it++;
		return (it);
	};

	iterator upper_bound(const key_type &k)
	{
		iterator it = this->begin();
		while (this->_comp(k, it->first) == false && it != this->end())
			it++;
		return (it);
	};

	const_iterator upper_bound(const key_type &k) const
	{
		const_iterator it = this->begin();
		while (this->_comp(k, it->first) == false && it != this->end())
			it++;
		return (it);
	};

	ft::pair<iterator,iterator> equal_range(const key_type &k)
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	};

	ft::pair<const_iterator,const_iterator> equal_range(const key_type &k) const
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	};

	allocator_type get_allocator(void) const
	{
		return (allocator_type());
	};

private:
	Node			*TNULL;
	allocator_type	_alloc;
	key_compare		_comp;

	void _null_node_create (void)
	{
		 TNULL = _alloc.allocate(1);
		this->_construct( TNULL);
		 TNULL->color = BLACK;
	};

	Node *_new_node(const value_type &val = value_type())
	{
		Node *new_node = _alloc.allocate(1);
		this->_construct(new_node, val);
		Node *parent = this->_find_parent( TNULL->right, val.first);
		if (parent ==  TNULL || !this->_comp(val.first, parent->key()))
			parent->right = new_node;
		else
			parent->left = new_node;
		new_node->parent = parent;
		this->_insertHelper(new_node);
		return (new_node);
	};

	void _construct(Node *x, const value_type &val = value_type())
	{
		Node tmp(val);
		tmp.left =  TNULL;
		tmp.right =  TNULL;
		tmp.parent =  TNULL;
		tmp.color =  RED;
		_alloc.construct(x, tmp);
	};

	void _node_swap(Node *a, Node *b)
	{
		if (a->left != b && a->left !=  TNULL)
			a->left->parent = b;
		if (a->right != b && a->right !=  TNULL)
			a->right->parent = b;
		if (a->parent != b && a->parent !=  TNULL)
		{
			if (a->parent->left == a)
				a->parent->left = b;
			else
				a->parent->right = b;
		}

		if (b->left != a && b->left !=  TNULL)
			b->left->parent = a;
		if (b->right != a && b->right !=  TNULL)
			b->right->parent = a;
		if (b->parent != a && b->parent !=  TNULL)
		{
			if (b->parent->left == b)
				b->parent->left = a;
			else
				b->parent->right = a;
		}

		if (a->parent == b)
			a->parent = a;
		if (a->left == b)
			a->left = a;
		if (a->right == b)
			a->right = a;
		if (b->parent == a)
			b->parent = b;
		if (b->left == a)
			b->left = b;
		if (b->right == a)
			b->right = b;
		ft::swap(a->parent, b->parent);
		ft::swap(a->left, b->left);
		ft::swap(a->right, b->right);
		ft::swap(a->color, b->color);
		if ( TNULL->right == a)
			 TNULL->right = b;
		else if ( TNULL->right == b)
			 TNULL->right = a;
	};

	void _deleteNode(Node *x, Node *child)
	{
		this->_deleteHelper(x, child);
		_alloc.destroy(x);
		_alloc.deallocate(x, 1);
	};

	Node *_findNode(Node *pos, const key_type &k) const
	{
		if (pos ==  TNULL || this->_equal(pos->key(), k))
			return (pos);
		else if (this->_comp(k, pos->key()))
			return (this->_findNode(pos->left, k));
		else
			return (this->_findNode(pos->right, k));
	};

	Node *_find_parent(Node *pos, const key_type &k) const
	{
		if (!this->_comp(k, pos->key()))
		{
			if (pos->right ==  TNULL)
				return (pos);
			else
				return (this->_find_parent(pos->right, k));
		}
		else
		{
			if (pos->left ==  TNULL)
				return (pos);
			else
				return (this->_find_parent(pos->left, k));
		}
	};

	Node *_minimum (Node *root) const
	{
		while (root->left != root->left->left)
			root = root->left;
		return (root);
	};

	bool _equal(const key_type &lhs, const key_type &rhs) const
	{
		return (this->_comp(lhs, rhs) == false && this->_comp(rhs, lhs) == false);
	};

	void _insertHelper (Node *x)
	{
		Node *parent = x->parent;
		Node *grandparent = parent->parent;
		Node *uncle = (grandparent->right == parent) ? grandparent->left : grandparent->right;

		if (parent ==  TNULL)
			x->color = BLACK;
		else if (parent->color == BLACK)
			return ;
		else if (uncle->color ==  RED)
		{
			parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color =  RED;
			this->_insertHelper(grandparent);
		}
		else if (uncle->color == BLACK)
		{
			if (grandparent->left->left == x || grandparent->right->right == x)
			{
				if (grandparent->left->left == x)
					this->_leftLeft(grandparent, parent);
				else if (grandparent->right->right == x)
					this->_rightRight(grandparent, parent);
				ft::swap(grandparent->color, parent->color);
			}
			else
			{
				if (grandparent->left->right == x)
					this->_leftRight(grandparent, parent, x);
				else if (grandparent->right->left == x)
					this->_rightLeft(grandparent, parent, x);
				ft::swap(grandparent->color, x->color);
			}
		}
	};

	void _deleteHelper (Node *v, Node *u)
	{
		if (v->color ==  RED || u->color ==  RED)
			u->color = BLACK;
		else
			this->_doubleBlack(u, v->parent);
	};

	void _doubleBlack (Node *u, Node *parent)
	{
		Node *sibling = (parent->left != u) ? parent->left : parent->right;

		if (u ==  TNULL->right)
			return ;
		else if (sibling->color == BLACK && (sibling->left->color ==  RED || sibling->right->color ==  RED))
		{
			if (sibling == parent->left && sibling->left->color ==  RED)
				this->_leftLeft(parent, sibling);
			else if (sibling == parent->left && sibling->right->color ==  RED)
				this->_leftRight(parent, sibling, sibling->right);
			else if (sibling == parent->right && sibling->right->color ==  RED)
				this->_rightRight(parent, sibling);
			else if (sibling == parent->right && sibling->left->color ==  RED)
				this->_rightLeft(parent, sibling, sibling->left);

			if (sibling->left->color ==  RED)
				sibling->left->color = BLACK;
			else
				sibling->right->color = BLACK;
		}
		else if (sibling->color == BLACK)
		{
			sibling->color =  RED;
			if (parent->color ==  RED)
				parent->color = BLACK;
			else
				this->_doubleBlack(parent, parent->parent);
		}
		else if (sibling->color ==  RED)
		{
			if (sibling == parent->left)
				this->_leftLeft(parent, sibling);
			else
				this->_rightRight(parent, sibling);
			ft::swap(parent->color, sibling->color);
			this->_doubleBlack(u, parent);
		}
	};

	void _leftLeft (Node *grandparent, Node *parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->right !=  TNULL)
			parent->right->parent = grandparent;
		grandparent->left = parent->right;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->right = grandparent;
	};

	void _rightRight (Node *grandparent, Node *parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->left !=  TNULL)
			parent->left->parent = grandparent;
		grandparent->right = parent->left;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->left = grandparent;
	};

	void _leftRight (Node *grandparent, Node *parent, Node *x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left !=  TNULL)
			x->left->parent = parent;
		if (x->right !=  TNULL)
			x->right->parent = grandparent;
		grandparent->left = x->right;
		parent->right = x->left;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = parent;
		x->right = grandparent;
	};

	void _rightLeft (Node *grandparent, Node *parent, Node *x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left !=  TNULL)
			x->left->parent = grandparent;
		if (x->right !=  TNULL)
			x->right->parent = parent;
		grandparent->right = x->left;
		parent->left = x->right;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = grandparent;
		x->right = parent;
	};
}; 


template <class Key, class T, class Compare, class Alloc>
bool operator== (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
{
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};

template <class Key, class T, class Compare, class Alloc>
bool operator<  (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};

template <class Key, class T, class Compare, class Alloc>
bool operator!= (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
{
	return (!(lhs == rhs));
};

template <class Key, class T, class Compare, class Alloc>
bool operator<= (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
{
	return (!(rhs < lhs));
};

template <class Key, class T, class Compare, class Alloc>
bool operator>  (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
{
	return (rhs < lhs);
};

template <class Key, class T, class Compare, class Alloc>
bool operator>= (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
{
	return (!(lhs < rhs));
};

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc> &x, map<Key,T,Compare,Alloc> &y)
{
	x.swap(y);
};

}

#endif