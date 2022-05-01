#include "easyfind.hpp"

int	main()
{
	std::vector<int> v(5, 5);

	std::cout << "values : " << std::endl;
	for (int i = 0; v[i];i++)
		v[i] = v[i] + i;
	for (int i = 0; v[i];i++)
		std::cout << v[i] << std::endl;
	try
	{
		std::cout << "find 5: " << easyfind(v, 5) << std::endl;
		std::cout << "find 6: " << easyfind(v, 6) << std::endl;
		std::cout << "find 10: " << easyfind(v, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
