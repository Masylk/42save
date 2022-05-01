#include <iostream>
#include "Array.hpp"

int	main()
{
	Array<std::string>	o(3);
	unsigned int	i = 0;

	while (i < 7)
	{
		try
		{
			std::cout << o[i++] << std::endl;
			o[i] = "oui";
		}
		catch (std::exception &e)
		{
			std::cout << "out of limits" << std::endl;
		}
	}
	std::cout << o.size() << std::endl;	
}
