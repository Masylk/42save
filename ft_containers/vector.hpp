#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include "random_access.hpp"
# include "reverse.hpp"
# include "template.hpp"
#include <unistd.h>

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
			typedef ft::random_access_iterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
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
				this->start = this->alloc.allocate(i);
				this->max = 0;
				this->elem_count = 0;
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
			//	*this = cpy;
			};
			
	//destructor
	//deallocate container and destroy its elements
	
			~vector()
			{
				clear();
				alloc.deallocate(start, capacity());
			};
				
		
			allocator_type	get_allocator() const
			{
				return this->alloc;
			};	

	//---ITERATORS START
	//
	
			const_iterator		begin(void) const {
				return (start);
			};
			
			iterator		begin(void) {
				return (start);
			};
			
			iterator		end(void) {
				if (this->empty())
				{
					return (this->begin());
				}
				return (start + elem_count);
			};
			
			const_iterator		end(void) const {
				if (this->empty())
					return (start);
				return (start + elem_count);
			};
			
			reverse_iterator	rbegin(void) {
				if (this->empty())
					return (rend());
				return (reverse_iterator(start + elem_count));
			};

			const_reverse_iterator	rbegin(void) const {
				if (this->empty())
					return (rend());
				return (reverse_iterator(start + elem_count));
			};
			
			reverse_iterator	rend(void) {
				return (reverse_iterator(start));
			};
			
			const_reverse_iterator	rend(void) const {
				return (reverse_iterator(start));
			};
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
				insert(begin(), rhs.begin(), rhs.end());
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
				this->alloc.deallocate(start, this->max);
			}
			
			void		realloc(size_type n)
			{
				size_type	i = 0;
				pointer		new_start;

				if (n < this->capacity())
					new_start = this->alloc.allocate(this->capacity());
				else
					new_start = this->alloc.allocate(n);
				if (n < this->size())
				{
					while (i < n)
					{
						this->alloc.construct((new_start + i), *(start + i));
						i++;
					}
				}
				else
				{
					while (i < this->size())
					{
						this->alloc.construct((new_start + i), *(start + i));
						i++;
					}
				}
				clear_container();
				deallocate_container();
				this->elem_count = i;
				start = new_start;
				container = start;
				if (n < this->capacity())
					this->max = this->capacity();
				else
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
				return (*start);
			};

			const_reference	front() const
			{
				return (*start);
			};
	
	//access last element
	
			reference	back()
			{
				return (*(start + this->size() - 1));
			};

			const_reference	back() const
			{
				return (*(start + this->size() - 1));
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
					realloc(n);
				}
				else
				{
					size_type	i = this->size();
					realloc(n);
					while (i < n)
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
			size_type	size = 0;
			
			InputIterator	tmp = first;
			while (tmp != last)
			{
				size++;
				tmp++;
			}
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
			while (i < n)
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
			return (this->erase(position, position + 1));	
		};

		iterator	erase(iterator first, iterator last)
		{
			iterator	tmp = first;
			size_type	erased = 0;
			iterator	end = this->end();
			iterator	tt = first;
			
			while (tt != last)
			{
				tt++;
				erased++;
			}
			while (last != end)
			{
				*first = *last;
				++first;
				++last;
			}
			while (erased-- > 0)
				alloc.destroy(start + --this->elem_count);
			return (tmp);	
		};


		iterator	insert(iterator position, const value_type &val)
		{
			size_type	pos = position - begin();
			
			this->insert(position, 1, val);
			return (iterator(begin() + pos)) ;
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
			difference_type const	i = position - this->begin();
			difference_type const	j = this->end() - this->begin();
			iterator		end;
			iterator		old_end;
			
			InputIterator	tmp = first;
			size_type	t = 0;

			while (tmp != last)
			{
				tmp++;
				t++;
			}
			this->resize(this->size() + t);
			end = this->end();
			position = this->begin() + i;
			old_end = this->begin() + j;
			while (old_end != position)
				*--end = *--old_end;
			while (first != last)
				*position++ = *first++;
		};

		void	push_back(const value_type &val)
		{

			if (this->size() == this->max)
			{
				if (this->max == 0)
					reserve(this->max + 1);
				else
					reserve((this->max) * 2);
			}
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
			while (lhs.begin() + i != lhs.end())
			{
				if (rhs.begin() + i == rhs.end() || *(lhs.begin() + i) != *(rhs.begin() + i)) 
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
				if (*(lhs.begin() + i) < *(rhs.begin() + i))
				       return (true);
				if (rhs.begin() + i == rhs.end() || *(rhs.begin() + i) < *(lhs.begin() + i))
					return (false);
				i++;
			}
			return (lhs != rhs);
		};
		
		template<typename T, typename Alloc>
		bool	operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			return (rhs < lhs);
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

		template<typename T, typename Alloc>
		void	swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y)
		{
			x.swap(y);
		}
	//
	//--RELATIONAL OPERATORS END
}

#endif
