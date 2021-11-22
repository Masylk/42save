#include <iostream>
#include "templates.hpp"

int	main()
{
	int	i = 2;
	int	j = 3;

	std::cout << "i: " << i << std::endl << "j: " << j << std::endl;
	std::cout << "max: " << max(i, j) << std::endl;
	std::cout << "min: " << min(i, j) << std::endl;
	::swap(i, j);
	std::cout << "after swap" << std::endl
		<< "i: " << i << std::endl << "j: " << j << std::endl;
}
