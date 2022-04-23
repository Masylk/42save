#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int	main(int ac, char **av)
{
	//Check if the arguments are corrects (3 arguments)
	if (ac != 4)
	{
		std::cout << "Need 3 Arguments" << std::endl;
		return (0);
	}

	//parse the arguments and check if they're not empty
	std::ifstream	istream(av[1]);
	std::string	out = std::string(av[1]) + ".replace";
	std::ofstream	ostream(&out[0]);
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	std::istreambuf_iterator<char>	eos;
	std::string	file(std::istreambuf_iterator<char>(istream), eos);

	istream.close();
	if (s1.empty() || s2.empty())
	{
		std::cout << "Arguments empty" << std::endl;
	}
	//Chercher dans le istream les occurences s1 pour ensuite les remplacer
	//par s2
	size_t	pos;
	while ((pos = file.find(s1)) != std::string::npos)
	{
		file.erase(pos, s1.length());
		file.insert(pos, s2);
	}
	//écrire dans le nouveau fichier ostream
	ostream << file;
}
