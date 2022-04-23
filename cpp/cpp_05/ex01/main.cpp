#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	*o;
	Form		*f;

	try
	{
		o = new Bureaucrat(1, "Bob");
		std::cout << *o << std::endl;
		o->downgrade();
		std::cout << "downgrade: ";
		std::cout << *o << std::endl;
		o->upgrade();
		std::cout << "upgrade: ";
		std::cout << *o << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	try
	{
		f = new Form("floom", 100, 100);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	o->signForm(f);

	delete o;
	delete f;
}
