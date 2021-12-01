#include "easyfind.hpp"

int	main()
{
	std::vector<int> v(5, 5);

	for (int value : v)
		std::cout << value << std::endl;
	try
	{
		std::cout << easyfind(v, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
