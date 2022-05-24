#include "span.hpp"
#include <stdlib.h>
#include <time.h>

void	addToSpan(Span *sp)
{	
	std::vector<int> tab;
    	std::vector<int>::iterator it;
	int	size;
	int	randSize = 20;
	int	threshold = 500;

	srand(time(NULL));
	size = rand() % randSize;
	for (int i = 0; i < size; i++)
		tab.push_back(rand() % threshold - rand() % threshold);
	for (it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	sp->addSpan(tab.begin(), tab.end());
}

int	main()
{
	Span	sp(10000);

	addToSpan(&sp);
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
