#include "vector.hpp"
#include <iostream>

int	main()
{
	int	*c;
	std::allocator<int> alloc;
	ft::vector<int>	o;

	(void)o;
	c = alloc.allocate(3);
	alloc.construct(c, 4);
	std::cout << c[0] << std::endl;
	std::cout << o.max_size() << std::endl;
	std::cout << o.size() << std::endl;
	std::cout << o.at(0) << std::endl;
	std::cout << c[1] << std::endl;
}
