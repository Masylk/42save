#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *arr, int len, void (*f)(T &))
{
	int	i;

	i = 0;
	while (i < len)
		f(arr[i++]);
}

#endif
