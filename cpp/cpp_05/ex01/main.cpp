#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	*o;
	Form		*f;

	try
	{
		o = new Bureaucrat(1, "Bob");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	try
	{
		f = new Form("floom", 100, 100);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	o->signForm(f);
}
