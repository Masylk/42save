#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*o;

	try
	{
		o = new Bureaucrat(1, "Bob");
		std::cout << *o << std::endl;	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	delete o;
}
