#include "span.hpp"

int	main()
{
	Span	sp(4);
	std::vector<int> tab{1, 2, 3, 45, 94, 8, -17, -329, 20000, 949, 39, 30};

	try
	{
		for (int value : tab)
			sp.addNumber(value);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{	
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
