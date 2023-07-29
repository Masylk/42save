#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <stack>

int	main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "----MutantStack----" << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;
	//mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator itb = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++itb;
	--itb;
	while (itb != ite)
	{
		std::cout << *itb << std::endl;
		++itb;
	}
	std::cout << "top: " << mstack.top() << std::endl;
	std::stack<int> s(mstack);


	std::list<int> mlist;
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "----List----" << std::endl;
	std::cout << "top: " << mlist.back() << std::endl;
	//mstack.pop();
	std::cout << "size: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator iteb = mlist.end();
	++it;
	--it;
	while (it != iteb)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "top: " << mlist.back() << std::endl;
	std::list<int> sb(mlist);

	std::cout << "--Reverse list--" << std::endl;
	std::list<int>::reverse_iterator rit = mlist.rbegin();
	std::list<int>::reverse_iterator riteb = mlist.rend();
	++rit;
	--rit;
	while (rit != riteb)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "--Reverse MutantStack--" << std::endl;
	MutantStack<int>::reverse_iterator ritb = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++ritb;
	--ritb;
	while (ritb != rite)
	{
		std::cout << *ritb << std::endl;
		++ritb;
	}

}
