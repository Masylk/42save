#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(int grade, std::string name) : name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else	
			this->grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name (cpy.getName())
						, grade(cpy.getGrade())
{
	*this = cpy;
}

Bureaucrat::~Bureaucrat()
{

}

//assign operator
const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	grade = rhs.getGrade();
	return *this;
}

//getter
const std::string	Bureaucrat::getName(void) const
{
	return this->name;
}

int			Bureaucrat::getGrade(void) const
{
	return this->grade;
}

//member functions
void	Bureaucrat::upgrade(void)
{
	if (this->grade > 1)
		this->grade--;
}

void	Bureaucrat::downgrade(void)
{
	if (this->grade < 150)
		this->grade++;
}

