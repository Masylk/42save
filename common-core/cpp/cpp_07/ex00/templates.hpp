#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
}

template<typename T>
int	min(T const &a, T const &b)
{
	return (a >= b ? b : a);
}

template<typename T>
int	max(T const &a, T const &b)
{
	return (a <= b ? b : a);
}


#endif
