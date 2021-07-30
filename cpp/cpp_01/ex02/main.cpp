#include <iomanip>
#include <iostream>

int	main(void)
{
	std::string s;
	std::string	*stringPTR;
	std::string	&stringREF = s;

	s = "HI THIS IS BRAIN";
	stringPTR = &s;
	std::cout << "string adress : " << (void*)s.data() << std::endl;
	std::cout << "ptr address : " << stringPTR << std::endl;
	std::cout << "ref address : " << (void*)stringREF.data() << std::endl;
	std::cout << "ptr : " << *stringPTR << std::endl;
	std::cout << "ref : " << stringREF << std::endl;
}
