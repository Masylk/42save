#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public :
		Fixed(void);
		//copy constructor
		Fixed(Fixed const & cpy);
		~Fixed(void);

		//assign
		Fixed &	operator=(Fixed const & rhs);
		//getter
		int		getRawBits(void) const;
		//setter
		void	setRawBits(int const raw);

	private :
		int value;
		//const bits value;
		static const int bits = 8;
};

#endif
