#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "vec_iterator.hpp"

namespace ft
{
	//make second template parameter Alloc
	template<typename T, typename Alloc = std::allocator<T> >
	class	vector
	{
		public :


		//------MEMBER TYPES----------
	typedef Alloc										allocator_type;
	typedef size_t										size_type;
	typedef typename allocator_type::reference 			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;

		//iterator
		//const_iterator
		//reverse_iterator
		//const_reverse_iterator
		//difference_type : voir au moment des iterator

			//default constructor
			//explicit vector (const allocator_type &alloc = allocator_tyoe());
			//
			//fill constructor
			//construct a container with n elements, each elements is a copy of val
			//explicit vector (size_type n, conts value_type& val = value_type(), const allocator_type &alloc = allocator_type());
			//
			//range constructor
			//Constructs a container with as many elements as the range (first, last),
			//with each element constructed from its corresponding element in that range in the same orde
			//template <typename InputIterator>
			//vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
			//
			//copy constructor
			//constructs a container with a copy of each elements in x, in the same order
			//vector (const vector &x)
			//
			//the container keeps an internal copy of alloc
			//the copy constructor creates a container that keeps and uses a copy of x allocator
			vector();
			vector(const vector &cpy);
			~vector()
			{
				//deallocate container and destroy its elements
			};
				

			//operator= : copy rhs container elements into this container (deleting the previous ones)
		private :
			T	*container;
	};
}

#endif
