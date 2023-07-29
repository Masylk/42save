#ifndef REVERSE_MAP_HPP
# define REVERSE_MAP_HPP

# include <iostream>
# include "iterator.hpp"
# include "iterators_tag.hpp"
#  include "map_iterator.hpp"

namespace ft
{
template<typename T>
class	reverse_iterator_map
{
	template <bool IsConst>
		class map_iterator {
		public:
			// Member types
			typedef					ft::pair<const Key, T>										pair_type;
			typedef typename		ft::conditional<IsConst, const pair_type, pair_type>::type	value_type;
			typedef typename		ft::conditional<IsConst, const node, node>::type			node_type;
			typedef					std::ptrdiff_t												difference_type;
			typedef					std::size_t													size_type;
			// -structors
			mapIterator				(void)														{ _ptr = NULL; }
			mapIterator				(node_type * const ptr)										{ _ptr = ptr; }
			~mapIterator			(void)														{}
			// Const stuff
			template <bool B>		mapIterator
				(const mapIterator<B> & x, typename ft::enable_if<!B>::type* = 0)				{ _ptr = x.getPtr(); }

			// Assignment
			mapIterator &			operator=	(const mapIterator & x)							{ _ptr = x.getPtr(); return (*this); }
			// Comparison
			template <bool B> bool	operator==	(const mapIterator<B> & x) const				{ return (_ptr == x.getPtr()); }
			template <bool B> bool	operator!=	(const mapIterator<B> & x) const				{ return (_ptr != x.getPtr()); }
			// -crementation
			mapIterator &			operator++	(void)											{ this->nextNode(); return (*this); }
			mapIterator &			operator--	(void)											{ this->prevNode(); return (*this); }
			mapIterator				operator++	(int)											{ mapIterator<IsConst> x(*this); this->nextNode(); return (x); }
			mapIterator				operator--	(int)											{ mapIterator<IsConst> x(*this); this->prevNode(); return (x); }
			// Dereference
			value_type &			operator*	(void) const									{ return (_ptr->data); }
			value_type *			operator->	(void) const									{ return (&_ptr->data); }
			// Member functions
			node_type *				getPtr		(void) const									{ return (_ptr); }

		private:
			node_type *				_ptr;

			void prevNode (void)
			{
				if (_ptr->right != _ptr->right->left)
				{
					_ptr = _ptr->right;
					while (_ptr->left != _ptr->left->left)
						_ptr = _ptr->left;
				}
				else
				{
					while (_ptr == _ptr->parent->right && _ptr != _ptr->parent)
						_ptr = _ptr->parent;
					_ptr = _ptr->parent;
				}
			}

			void nextNode (void)
			{
				if (_ptr == _ptr->parent)
				{
					while (_ptr->right != _ptr->right->left)
						_ptr = _ptr->right;
				}
				else if (_ptr->left != _ptr->left->left)
				{
					_ptr = _ptr->left;
					while (_ptr->right != _ptr->right->left)
						_ptr = _ptr->right;
				}
				else
				{
					while (_ptr == _ptr->parent->left && _ptr != _ptr->parent)
						_ptr = _ptr->parent;
					_ptr = _ptr->parent;
				}
			}
		}; // Iterator
}
#endif
