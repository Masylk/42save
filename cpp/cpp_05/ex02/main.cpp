#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

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
	}
	try
	{
		f = new ShrubberyCreationForm("targetto");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	o->signForm(*f);
}
