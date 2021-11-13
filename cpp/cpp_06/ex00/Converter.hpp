#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits>

class	Converter
{
	public :
		//constructors
		Converter();
		Converter(char *str);
		Converter(const Converter &cpy);
		~Converter();

		//assign operator
		const	Converter&operator=(const Converter &rhs);

		//converters
		bool	toFloat(char *str);
		bool	toDouble(char *str);
		bool	toInt(char *str);
		bool	toChar(char *str);
	
		//getters
		float	getFloat() const;
		double	getDouble() const;
		int	getInt() const;
		char	getChar() const;
		char	*getBase() const;

		//printers
		void	printFloat();
		void	printDouble();
		void	printInt();
		void	printChar();
	
		//checkers
		bool	strDigit(char *str);
	class	ImpossibleException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("impossible");
			}
	};
	class	NonDisplayableException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Non Displayable");
			}
	};
	private :
		float	f;
		int	i;
		char	c;
		double	d;
		double	baseconv;
		bool	numconv;
		char	*base;
};

#endif
