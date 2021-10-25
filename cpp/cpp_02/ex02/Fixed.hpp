#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class	Fixed
{
	public :
		Fixed(void);
		//parametric constructor
		Fixed(int const val);
		Fixed(float const val);
		//copy constructor
		Fixed(Fixed const & cpy);
		~Fixed(void);

		//assign
		Fixed &	operator=(Fixed const & rhs);
		//Comparison operators
		bool	operator>(Fixed const & rhs);
		bool	operator<(Fixed const & rhs);
		bool	operator>=(Fixed const & rhs);
		bool	operator<=(Fixed const & rhs);
		bool	operator==(Fixed const & rhs);
		bool	operator!=(Fixed const & rhs);
		//Arithmetic operators
		float	operator*(Fixed const & rhs);
		float	operator+(Fixed const & rhs);
		float	operator-(Fixed const & rhs);
		float	operator/(Fixed const & rhs);
		//getter
		int		getRawBits(void) const;
		//setter
		void	setRawBits(int const raw);
		//float converter
		float	toFloat(void) const;
		//int converter
		int		toInt(void) const;
	private :
		int value;
		//const bits value;
		static const int bits = 8;
};

//overload de loperateur << representant le nombre a point fixe
std::ostream	& operator<<(std::ostream &o, Fixed const & rhs);

#endif
