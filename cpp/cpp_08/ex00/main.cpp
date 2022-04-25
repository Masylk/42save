#include "easyfind.hpp"

int	main()
{
	std::vector<int> v(5, 5);

	for (int i = 0; v[i];i++)
		std::cout << v[i] << std::endl;
	try
	{
		std::cout << easyfind(v, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
