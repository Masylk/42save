#include "Fixed.hpp"

#include <iostream>

int	main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	c.setRawBits(50.3040);
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
