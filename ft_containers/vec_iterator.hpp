#ifndef VEC_ITERATOR_HPP
# define VEC_ITERATOR_HPP

# include <iostream>
# include <iterator>

class	IteratorVec : public std::iterator<std::random_access_iterator_tag, int>
{
	public :
		IteratorVec(int *x) : i(x) {};
		IteratorVec(const IteratorVec &cpy) : i(cpy.i) {};
		~IteratorVec() {};

		IteratorVec	&operator++() 
		{
			++i;
			return *this;
		}
		IteratorVec	operator++(int)
		{
			IteratorVec	tmp(*this);
			
			++i;
			return (tmp);
		}
		bool	operator==(const IteratorVec &rhs) const{
			return rhs.i == i;
		};
		bool	operator!=(const IteratorVec &rhs) const{
			return rhs.i != i;
		};
		int		&operator*(){
			return *i;
		};

	private :
			int	*i;
};

#endif
