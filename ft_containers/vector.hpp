#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include "vec_iterator.hpp"
//add un fichier pour chaque categorie :
//# include "iterators.hpp"
//# include "capacity.hpp"
//# include "modifiers.hpp"
//# include "access.hpp"


//allocator doc :
//
//address(reference x)
//returns the address of x;
//
//allocate(size_t n)
//try to allocate memory and return a pointer to the address allocated
//throw bad_alloc if it fails
//
//deallocate(pointer x, size_t n)
//release memory allocated, elements within the array are not deallocated
//
//destroy(pointer p)
//destroy the object (call the destructor)
//
//construct(pointer p, const_reference val)
//construct an element object on the location pointed by p
//



namespace ft
{
	//make second template parameter Alloc
	template<typename T, typename Alloc = std::allocator<T> >
	class	vector
	{
		public :


	//---MEMBER TYPES START
	//
	
			typedef Alloc										allocator_type;
			typedef size_t										size_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef T							value_type;
			typedef ft::IteratorVec<value_type>	iterator;
		//const_iterator
		//reverse_iterator
		//const_reverse_iterator
		//difference_type : voir au moment des iterator

	//
	//---MEMBER TYPES END

	//---CONSTRUCTORS START
	//
	
	//default constructor
			
			explicit vector(const allocator_type &alloc = allocator_type())
			{
				this->alloc = alloc;
				start = NULL;
				max = 0;
				elem_count = max;
			};
			
	//fill constructor
	//construct a container with n elements, each elements is a copy of val
			
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type &alloc = allocator_type())
			{
				this->alloc = alloc;
				start = alloc.allocate(n);
				max = 0;
				while (n)
				{
					alloc.construct(start + max, val);
					max++;
					n--;
				}
				elem_count = max;
			};
	
	//range constructor
	//Constructs a container with as many elements as the range (first, last),
	//with each element constructed from its corresponding element in that range in the same orde
			
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
			{
			//	difference_type n = distance(first, last);
			//	start = alloc.allocate(n);
				max = 0;
				elem_count = 0;
				this->alloc = alloc;
				while (first != last)
				{
					alloc.construct(start + max, *first);
					first++;
					max++;
					elem_count++;
				}
			};
			
	//copy constructor
	//constructs a container with a copy of each elements in x, in the same order
	//the container keeps an internal copy of alloc
	//the copy constructor creates a container that keeps and uses a copy of x allocator
			
			vector(const vector &cpy);
			
	//destructor
	//deallocate container and destroy its elements
	
			~vector()
			{
			};
				
			
	//---ITERATORS START
	//
	
			iterator	begin(){return start;};
			iterator	end(){return start + max;};
			//operator= : copy rhs container elements into this container (deleting the previous ones)
	
	//
	//---ITERATORS END		
			
	//---ALLOCATION UTILS START		
	//
			
			void		clear_container()
			{
				size_type	i = 0;

				while (i < this->size())
					this->alloc.destroy(start + i++);
				elem_count = 0;
			}

			void		deallocate_container()
			{
				this->alloc.deallocate(start, this->size());
			}
			
			void		realloc(size_type n)
			{
				size_type	i = 0;
				pointer	new_start;

				elem_count = 0;
				new_start = this->alloc.allocate(n);
				while (i < this->size())
				{
					this->alloc.construct(new_start, start + i++);
					elem_count++;
				}
				clear_container();
				deallocate_container();
				start = new_start;
				this->max = n;
			};

	//
	//---ALLOCATION UTILS END

	//---ELEMENT ACCESS START
	//
	
	//access element at n pos
	
			reference	operator[](size_type n)
			{
				return (*(start + n));
			};

			const_reference	operator[](size_type n) const
			{
				return (*(start + n));
			};

	//access element at n pos (handle out_of_range exception)
			
			reference	at(size_type n)
			{
				if (n > this->size())
					throw std::out_of_range("out of range");
				return (*(start + n));
			};

			const_reference	at(size_type n) const
			{
				if (n > this->size())
					throw std::out_of_range("out of range");
				return (*(start + n));
			};

	//access first element
	
			reference	front()
			{
				return (start);
			};

			const_reference	front() const
			{
				return (start);
			};
	
	//access last element
	
			reference	back()
			{
				return (start + this->size());
			};

			const_reference	back() const
			{
				return (start + this->size());
			};
	
	//access container
	
			value_type	*data()
			{
				return (container);
			};

			const value_type *data() const
			{
				return (container);
			};
	
	//
	//---ELEMENT ACCESS END

	//---CAPACITY FUNCTIONS START
	//

	//number of elements in the container
	
			size_type	size() const
			{
				return this->elem_count;
			};

	//maximum storage allocatable
	
			size_type	max_size() const
			{
				return this->alloc.max_size();
			};
			
	//maximum storage allocated
	
			size_type	capacity() const
			{
				return this->max;
			};

	//check if container has no element
	
			bool		empty() const
			{
				return (this->size() == 0);
			};
		
	//reallocate to gain capacity
	
			void		reserve(size_type n)
			{
				if (n > this->capacity())
					realloc();
			};
		
	//resize to fit size
	
			void		shrink_to_fit()
			{
				realloc(this->size());
			};
		
	//resize the container, if n is smaller destroy the elements until size = n
	
			void		resize(size_type n, const value_type &val = value_type())
			{
				if (n < this->size())
				{
					int i = n;
					while (i < this->size())
						this->alloc.destroy(start + i++);
				}
				else
				{
					int	i = this->size();
					realloc(n);
					while (i < this->max)
					{
						alloc.construct(start + i++, val);
						elem_count++;
					}
				}
			};

	//
	//---CAPACITY FUNCTIONS END
	
	//---MODIFIERS START
	//

	/*	template<typename InputIterator>
	void	assign(InputIterator first, InputIterator last)
		{
			(void)first;
			(void)last;
		};*/

		void	assign(size_type n, const value_type &val)
		{
			size_type	i = 0;

			clear_container();
			realloc(n);
			std::cout << "intern test : " <<  max << std::endl;
			while (i < max)
			{
				std::cout << "intern test : " <<  start + i << std::endl;
				alloc.construct(start + i++, val);
				elem_count++;
			}
		};

	//
	//---MODIFIERS END
	
		private :
			allocator_type	alloc;
			pointer		start;
			size_type	max;
			size_type	elem_count;
			T		*container;
	};
}

#endif
