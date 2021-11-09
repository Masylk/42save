#include "Intern.hpp"


Intern::Intern()
{
	this->forms[0].name = "robotomy request";
	this->forms[0].ptr = new RobotomyRequestForm("fodder");
	this->forms[1].name = "shrubbery creation";
	this->forms[1].ptr = new ShrubberyCreationForm("fodder");
	this->forms[2].name = "presidential pardon";
	this->forms[2].ptr = new PresidentialPardonForm("fodder");
}

Intern::Intern(const Intern &cpy)
{
	*this = cpy;
}

Intern::~Intern()
{
	int	i;

	std::cout << "DELETING INTERN" << std::endl;
	i = 0;
	while (i < 3)
		delete this->forms[i++].ptr;
}

//assign operator
const Intern &Intern::operator=(const Intern &rhs)
{
	*this = rhs;
	return *this;
}

Form	*Intern::makeForm(std::string form, std::string target)
{
	Form	*res;
	int	i;

	i = 0;
	res = NULL;
	try
	{
		while (i < 3)
		{
			if (form == this->forms[i].name)
			{
				throw this->forms[i].ptr->factoryForm(target);
				break;
			}
			i++;
		}
		if (i == 3)
			std::cout << "requested form [" << form << "] is unknown"
				<< std::endl;
	}
	catch (Form *e)
	{
		res = e;
	}
	return res;
}
