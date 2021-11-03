#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*o;

	try
	{
		o = new Bureaucrat(1, "Bob");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	(void)o;
}
