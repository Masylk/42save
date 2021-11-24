#include <iostream>
#include "Array.hpp"

int	main()
{
	int	*a = new int();
	Array<std::string>	o(1);
	unsigned int	i = 0;

	while (i < 7)
	{
		try
		{
			std::cout << o[i++] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "out of limits" << std::endl;
		}
	}	
	std::cout << *a << std::endl;
}
