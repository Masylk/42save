#include "iter.hpp"
#include <iostream>

/*template <typename T>
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
}*/


class Awesome {

public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }

private:
    int _n;
};

std::ostream&
operator<<( std::ostream & o, Awesome const & rhs )
{ o << rhs.get(); return o; }

template< typename T >
void print( T const & x )
{ std::cout << x << std::endl; return; }

int main() {

int tab[] = { 0, 1, 2, 3, 4 };
Awesome tab2[5];

iter( tab, 5, print );
iter( tab2, 5, print );

return 0;
}
