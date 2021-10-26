#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
		
	//static functions
		static Fixed 		&min(Fixed &lhs, Fixed &rhs);
		static const Fixed 	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed 		&max(Fixed &lhs, Fixed &rhs);
		static const Fixed 	&max(const Fixed &lhs, const Fixed &rhs);
	
	//assign
		Fixed &	operator=(Fixed const & rhs);
		
	//Comparison operators
		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;
		
	//Arithmetic operators
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);
	
	//Increment Operators
		Fixed	operator++(void);	
		Fixed	operator++(int);	
		Fixed	operator--(void);	
		Fixed	operator--(int);	
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
Fixed 		&min(Fixed &lhs, Fixed &rhs);
const Fixed 	&min(const Fixed &lhs, const Fixed &rhs);
Fixed 		&max(Fixed &lhs, Fixed &rhs);
const Fixed 	&max(const Fixed &lhs, const Fixed &rhs);

#endif
