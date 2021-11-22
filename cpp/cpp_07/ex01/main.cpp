#include "iter.hpp"
#include <iostream>

template <typename T>
int	ft_strlen(T *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
template <typename T>
void	print(T &v)
{
	std::cout << v << std::endl;
}

int	main()
{
	char	t[] = {'o', 'u', 'i', 'n', 'o', 'n'};
	int	o[] = {1, 2, 4, 5, 8, 9};
	int	size_o = 6;

	iter(t, ft_strlen(t), &print);
	iter(o, size_o, &print);
}
