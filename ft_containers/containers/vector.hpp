#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include "random_access.hpp"
# include "reverse.hpp"
# include "iterator.hpp"
# include "template.hpp"

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
	//Container and alloc Types
			typedef Alloc										allocator_type;
			typedef size_t										size_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef T							value_type;
	//Iterator Types
			typedef ft::random_access_iterator<value_type>				iterator;
			typedef const ft::random_access_iterator<value_type>			const_iterator;
			typedef ft::reverse_iterator<value_type>				reverse_iterator;
			typedef const ft::reverse_iterator<value_type>				const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

	//
	//---MEMBER TYPES END

	//---CONSTRUCTORS START
	//
	
	//default constructor
			
			explicit vector(const allocator_type &alloc = allocator_type())
			{
				this->alloc = alloc;
				this->start = NULL;
				this->max = 0;
				this->elem_count = max;
			};
			
	//fill constructor
	//construct a container with n elements, each elements is a copy of val
			
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type &alloc = allocator_type())
			{
				this->alloc = alloc;
				start = this->alloc.allocate(n);
				max = 0;
				while (n)
				{
					this->alloc.construct(start + max, val);
					max++;
					n--;
				}
				elem_count = max;
			};
	
	//range constructor
	//Constructs a container with as many elements as the range (first, last),
	//with each element constructed from its corresponding element in that range in the same orde
			
			template <typename InputIterator>
			explicit vector (InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type	i = 1;
				InputIterator	tmp = first;

				this->alloc = alloc;
				while (tmp != last)
				{
					tmp++;
					i++;
				}
			//	difference_type n = distance(first, last);
				start = this->alloc.allocate(i);
				max = 0;
				elem_count = 0;
				this->alloc = alloc;
				while (first != last)
				{
					this->alloc.construct(start + max, *first);
					first++;
					max++;
					elem_count++;
				}
			};
			
	//copy constructor
	//constructs a container with a copy of each elements in x, in the same order
	//the container keeps an internal copy of alloc
	//the copy constructor creates a container that keeps and uses a copy of x allocator
			
			vector(const vector &cpy)
			{
				this->alloc = cpy.alloc;
				start = this->alloc.allocate(cpy.capacity());
				elem_count = 0;
				max = 0;
				insert(begin(), cpy.begin(), cpy.end());	
			};
			
	//destructor
	//deallocate container and destroy its elements
	
			~vector()
			{
				clear();
				alloc.deallocate(start, capacity());
				std::cout << "Destructor called !" << std::endl;
			};
				
		
			allocator_type	get_allocator() const
			{
				return this->alloc;
			};	
	//---ITERATORS START
	//
	
			iterator		begin(void) {return (start);};
			
			const_iterator		cbegin(void) const {return (start);};
			
			iterator		end(void) {
				if (this->empty())
				{
					return (this->begin());
				}
				return (start + elem_count);
			};
			
			const_iterator		cend(void) const {
				if (this->empty())
					return (start);
				return (start + elem_count);
			};
			
			reverse_iterator	rbegin(void) const {
				if (this->empty())
					return (rend());
				return (start + elem_count);
			};

			const_reverse_iterator	crbegin(void) const {return (begin());};
			
			reverse_iterator	rend(void) const {
				return (start);
			};
			
			const_reverse_iterator	crend(void) const {return (rend());};
			//operator= : copy rhs container elements into this container (deleting the previous ones)

	//
	//---ITERATORS END		
		
	//---OPERATORS START
	//
	
			vector	&operator=(const vector &rhs)
			{
				//faire operator ==
				if (*this == rhs)
					return (*this);
				clear();
				insert(cbegin(), rhs.cbegin(), rhs.cend());
				return (*this);
			};

		

	//	
	//---OPERATORS END

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
				pointer		new_start;

				new_start = this->alloc.allocate(n);
				
				while (i < this->size())
				{
					this->alloc.construct((new_start + i), *(start + i));
					i++;
				}
				clear_container();
				deallocate_container();
				this->elem_count = i;
				start = new_start;
				container = start;
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
					realloc(n);
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
					size_type	i = n;
					while (i < this->size())
					{
						this->alloc.destroy(start + i++);
						elem_count--;
					}
				}
				else
				{
					size_type	i = this->size();
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

	//----TODO
	template<typename InputIterator>
		void	assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_type	i = 0;
			size_type	size = last - first;
			
			//std::cout << isIterator<InputIterator>() << std::endl;
			clear_container();
			realloc(size);
			while (i < size)
			{
				alloc.construct(start + i++, *(first++));
				elem_count++;
			}
		};

		void	assign(size_type n, const value_type &val)
		{
			size_type	i = 0;

			clear_container();
			realloc(n);
			while (i < max)
			{
				alloc.construct(start + i++, val);
				elem_count++;
			}
		};


		void	clear()
		{
			clear_container();
		};

		iterator	erase(iterator position)
		{
			size_type	pos = position - begin();
			int		erased = 0;

			alloc.destroy(start + pos);
			erased++;
			size_type	i = pos + 1;
			while 	(i < elem_count)
			{
				alloc.construct(start + (i - erased), *(start + i));
				alloc.destroy(start + i);
				i++;
			}
			elem_count--;
			return (start + pos);	
		};

		iterator	erase(iterator first, iterator last)
		{
			int		erased = 0;
			size_type	pos = first - begin();
			
			while (&(*first) != &(*last) + 1 )
			{
				alloc.destroy(&(*(first++)));
				erased++;
			}
			size_type	i = pos + 1;
			while 	(i < elem_count)
			{
				alloc.construct(start + (i - erased), *(start + i));
				alloc.destroy(&(*last) + i);
				i++;
			}
			elem_count -= erased;
			return (&(*last) + 1);	
		};


		iterator	insert(iterator position, const value_type &val)
		{
			T	tmp;
			size_type	pos = position - begin();

			tmp = *position;
			realloc(elem_count + 1);
			*(start + pos) = val;
			pos++;

			T	swp;
			while (pos < max)
			{
				swp = *(start + pos);
				*(start + pos) = tmp;
				tmp = swp;
				pos++;
			}
			elem_count++;
			return position;
		};

		void	insert(iterator position, size_type n, const value_type &val)
		{
			ft::vector<T>		tmp;
			size_type		pos = position - begin();

			tmp.assign(&(*begin()) + pos, &(*end()));
			realloc(elem_count + n);
			for (size_type i = 0; i < n; i++)
			{
				*(start + pos) = val;
				pos++;
			}
			int	i = 0;
			while (pos < max)
			{
				*(start + pos) = *(&(*tmp.begin()) + i);
				i++;
				pos++;
			}
			tmp.clear_container();
			elem_count += n;
		};

		template<typename InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			ft::vector<T>		tmp;
			size_type		pos = position - begin();
			difference_type		range = last - first;

			tmp.assign(&(*begin()) + pos, &(*end()));
			realloc(elem_count + range);
			while (first != last)
			{
				*(start + pos) = *(first)++;
				pos++;
			}
			int	i = 0;
			while (pos < max)
			{
				*(start + pos) = *(&(*tmp.begin()) + i);
				i++;
				pos++;
			}
			tmp.clear_container();
			elem_count += range;
		};

		void	push_back(const value_type &val)
		{

			if (this->size() == this->max)
				reserve(this->max + 2);
			alloc.construct(start + this->size(), val);
			elem_count++;
		};

		void	pop_back()
		{
			alloc.destroy(start + this->size());
			elem_count--;	
		};

		void	swap(vector &x)
		{
			pointer		tmp;
			size_type	t_elem_count;
			size_type	t_max;

			tmp = start;
			t_elem_count = elem_count;
			t_max = max;
			start = x.start;
			elem_count = x.elem_count;
			max = x.max;
			x.max = t_max;
			x.elem_count = t_elem_count;
			x.start = tmp;
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
	//
	//---END OF VECTOR CLASS

	//---RELATIONAL OPERATORS START
	//
		template<typename T, typename Alloc>
		bool	operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			typename ft::vector<T, Alloc>::size_type	i = 0;
			while (lhs.cbegin() + i != lhs.cend())
			{
				if (rhs.cbegin() + i == rhs.cend() || *(lhs.cbegin() + i) != *(rhs.cbegin() + i)) 
					return (false);
				i++;
			}
			return (true);
		};

		template<typename T, typename Alloc>
		bool	operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			typename ft::vector<T, Alloc>::size_type	i = 0;
			while (lhs.begin() + i != lhs.end())
			{
				if (*(lhs.cbegin() + i) < *(rhs.cbegin() + i))
				       return (true);
				if (rhs.cbegin() + i == rhs.cend() || *(rhs.cbegin() + i) < *(lhs.cbegin() + i))
					return (false);
				i++;
			}
		};
		
		template<typename T, typename Alloc>
		bool	operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			return (!(lhs < rhs));
		};
	
		template<typename T, typename Alloc>
		bool	operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			return ((lhs < rhs) || (lhs == rhs));
		};

		template<typename T, typename Alloc>
		bool	operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			return (!(lhs < rhs) || (lhs == rhs));
		};

		template<typename T, typename Alloc>
		bool	operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			return (!(lhs == rhs));
		};

	//
	//--RELATIONAL OPERATORS END
}

#endif
