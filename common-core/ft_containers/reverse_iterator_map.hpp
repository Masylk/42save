#ifndef REVERSE_ITERATOR_MAP_HPP
# define REVERSE_ITERATOR_MAP_HPP

namespace ft
{
	//////////////////////////////
	// Reverse iterator
	//////////////////////////////

	template <class it>
	class reverse_iterator_map {
	public:
		// -structors
		reverse_iterator_map			(void)
		{
			_it = it();
		};

		reverse_iterator_map			(typename it::value_type * ptr)
		{
			_it = it(ptr);
		};

		reverse_iterator_map			(const it & x)
		{
			_it = x; --_it;
		};

		~reverse_iterator_map			(void){};
		
		template <class U>
		reverse_iterator_map			(const reverse_iterator_map<U> & x)
		{
			_it = x.getIt();
		};

		// -crementation
		reverse_iterator_map	&operator++(void)
		{
			--_it; return (*this);
		};

		reverse_iterator_map 	&operator--(void)
		{ 
			++_it; return (*this);
		};

		reverse_iterator_map	operator++(int)
		{ 
			reverse_iterator_map<it> x(*this); 
			--_it; return (x); 
		};
		
		reverse_iterator_map	operator--(int){
			reverse_iterator_map<it> x(*this);
			++_it;
			return (x);
		};

		// Operation
		reverse_iterator_map	operator+(int n) const
		{
			return (_it - n + 1);
		};

		reverse_iterator_map	operator-(int n) const							
		{ 
			return (_it + n + 1); 
		};

		std::ptrdiff_t		operator-(const reverse_iterator_map & x) const		
		{ 
			return (x.getIt() - _it);
		};
		
		// Dereference
		typename it::value_type 	&operator[](size_t n) const						
		{ 
			return (*(_it - n)); 
		};

		typename it::value_type 	&operator*(void) const							
		{ 
			return (*_it); 
		};

		typename it::value_type 	*operator->(void) const							
		{ 
			return (&(*_it)); 
		};
		
		it	base(void)									
		{ 
			return (++it(_it));
		};

		it	getIt(void) const							
		{ 
			return (_it); 
		};

		reverse_iterator_map	&operator=	(const reverse_iterator_map & x)
		{
			_it = x.getIt(); return (*this);
		};

		reverse_iterator_map	&operator+=	(int n)
		{ 
			_it -= n; return (*this);
		};

		reverse_iterator_map	&operator-=	(int n)
		{
			_it += n; return (*this);
		};

		template <class U>
		bool		operator==(const reverse_iterator_map<U> & x) const
		{ 
			return (_it == x.getIt());
		};
		
		template <class U>
		bool		operator!=(const reverse_iterator_map<U> & x) const
		{ 
			return (_it != x.getIt());
		};

		template <class U>
		bool		operator<(const reverse_iterator_map<U> & x) const
		{ 
			return (_it > x.getIt());
		};

		template <class U>
		bool		operator>(const reverse_iterator_map<U> & x) const
		{ 
			return (_it < x.getIt());
		};

		template <class U>
		bool		operator<=(const reverse_iterator_map<U> & x) const	
		{ 
			return (_it >= x.getIt()); 
		};

		template <class U>
		bool		operator>=(const reverse_iterator_map<U> & x) const
		{ 
			return (_it <= x.getIt());
		};

		friend reverse_iterator_map		operator+(int n, const reverse_iterator_map & x)		
		{ 
			return (x.getIt() - n + 1); 
		};

	private:
		it		_it;
	};
}

#endif