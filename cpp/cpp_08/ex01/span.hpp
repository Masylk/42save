#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class	Span
{
	public :
		Span(unsigned int n);
		Span(const Span &cpy);
		~Span();

		const Span	&operator=(const Span &rhf);
		unsigned int	getSize(void) const;
		void		addNumber(int n);
		long		shortestSpan(void);
		long		longestSpan(void);

	class	MaxCapacityException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("can't add : max capacity.");
			}
	};
	class	NoSpanException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("no span to calculate.");
			}
	};
	private :
		std::vector<int>	v;
		unsigned int		size;
};

#endif
