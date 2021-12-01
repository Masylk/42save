#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft
{
	//make second template parameter Alloc
	template<typename T, typename Alloc = std::allocator<T>>
	class	vector
	{
		public :
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
			vector<T>();
			vector<T>(const vector &cpy);
			~vector<T>();
		typedef std::allocator<T> allocator_type;
				
		private :
			T	*container;
	};
}

#endif
