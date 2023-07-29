#include "Converter.hpp"

int	main(int ac, char **av)
{
	Converter *c;
	if (ac != 2)
		return (0);
	c = new Converter(av[1]);
	c->printChar();
	c->printInt();
	c->printFloat();
	c->printDouble();
	delete c;
}
