#include "mutantstack.hpp"

int	main()
{
	MutantStack<int>	a;

	a.push(5);
	a.push(15);
	a.push(53);
	a.push(325);

	std::cout << a.top() << std::endl;
	
	MutantStack<int>::iterator		it = a.begin();
	MutantStack<int>::reverse_iterator	itr = a.rbegin();

	std::cout << *it << std::endl;
	std::cout << *itr << std::endl;
}
