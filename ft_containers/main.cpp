#include "vector.hpp"
#include <iostream>

template<typename T, typename A>
void	print_vec(ft::vector<T, A> const &v)
{
	typename ft::vector<T>::iterator	it = v.begin();
	
	std::cout << "vector size : " << v.size() << std::endl;
	std::cout << "vector content: " << std::endl;
	while (it != v.end())
	{
		std::cout << *(it++);
		if (it != v.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int	main()
{
	int	tab[] = {1, 2};
	ft::vector<int>	o(tab, tab + 2);
	ft::vector<int>	v(o);

	(void)tab;
	std::cout << "creation : " << std::endl;
	print_vec(o);
	print_vec(v);
	std::cout << "--------------------------------" << std::endl;
	o.assign(7, 3);
	std::cout << "assign : " << std::endl;
	print_vec(o);
/*	std::cout << "--------------------------------" << std::endl;
	o.push_back(223);	
	std::cout << "push_back : " << std::endl;
	print_vec(o);
	std::cout << "--------------------------------" << std::endl;
	o.pop_back();	
	std::cout << "pop_back : " << std::endl;
	print_vec(o);
	std::cout << "--------------------------------" << std::endl;
	o.swap(v);
	std::cout << "swap with empty : " << std::endl;
	print_vec(o);
	std::cout << "--------------------------------" << std::endl;
	o.swap(v);
	std::cout << "swap back : " << std::endl;
	print_vec(o);
*/
	std::cout << "--------------------------------" << std::endl;
	
	ft::IteratorVec<int> b = o.begin();
	std::cout << "begin : " << *b << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "assign to v : " << std::endl;
	v.assign(tab, tab + 1);
	v.insert(v.begin(), tab, tab + 2);
	std::cout << "---V--- : " << std::endl;
	print_vec(v);
	std::cout << "---O--- : " << std::endl;
	print_vec(o);

	std::cout << "--------------------------------" << std::endl;
	
//	ft::IteratorVec<int> b = o.begin();
	std::cout << "begin : " << *b << std::endl;
	

}
