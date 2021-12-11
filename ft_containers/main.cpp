#include "vector.hpp"
#include <iostream>

int	main()
{
	ft::vector<int>	o;

	o.assign(5, 1);
	//std::cout << o[0] << std::endl;
	//std::cout << o.size() << std::endl;
	std::cout << "size : " << o.size() << std::endl;
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	o.push_back(223);	
	std::cout << "size : " << o.size() << std::endl;
	std::cout << o[o.size() - 1] << std::endl;
	//std::cout << o.max_size() << std::endl;
	//std::cout << o.size() << std::endl;
	//std::cout << o.at(0) << std::endl;
}
