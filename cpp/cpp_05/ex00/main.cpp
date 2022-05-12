#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*o;

	try
	{
		o = new Bureaucrat(1, "Bob");
		std::cout << "create : " << *o << std::endl;	
		o->downgrade();
		std::cout << "dowgrade : " << *o << std::endl;	
		o->upgrade();
		std::cout << "upgrade : " << *o << std::endl;	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	delete o;
}
