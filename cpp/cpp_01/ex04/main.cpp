#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Need 3 Arguments" << std::endl;
		return (0);
	}

	std::ifstream	istream(av[1]);
	std::ofstream	ostream("replace.out");
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	std::istreambuf_iterator<char>	eos;
	std::string	debug(std::istreambuf_iterator<char>(istream), eos);

	istream.close();
	ostream << debug;
	if (s1.empty() || s2.empty())
	{
		std::cout << "Arguments empty" << std::endl;
	}
}
