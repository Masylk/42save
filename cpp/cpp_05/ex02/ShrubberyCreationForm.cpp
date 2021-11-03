#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form{"ShrubberyCreationForm", 137 , 145}
, gradeEx(137), gradeS(145), name("ShrubberyCreationForm"), target(target)
{
	this->isSigned = false;
	if (gradeEx < 1 || gradeS < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (gradeEx > 150 || gradeS > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : Form(cpy.getName(), cpy.getGradeEx()
	, cpy.getGradeS()), gradeEx(cpy.getGradeEx()), gradeS(cpy.getGradeS()), name(cpy.getName()), target(cpy.getTarget())
{
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

//assign operator
const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	this->isSigned = rhs.getIsSigned();
	return *this;
}

//getter
const std::string	ShrubberyCreationForm::getName(void) const
{
	return this->name;
}

const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return this->target;
}

int			ShrubberyCreationForm::getGradeEx(void) const
{
	return this->gradeEx;
}

int			ShrubberyCreationForm::getGradeS(void) const
{
	return this->gradeS;
}

bool		ShrubberyCreationForm::getIsSigned(void) const
{
	return this->isSigned;
}

ShrubberyCreationForm	&ShrubberyCreationForm::beSigned(const Bureaucrat &b)
{
	try
	{
		if (this->gradeS < b.getGrade())
			throw ShrubberyCreationForm::GradeTooLowException();
		else
			this->isSigned = true;
	}
	catch (ShrubberyCreationForm::GradeTooLowException e)
	{
		std::cout << e.what();
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (isExecutable(executor, *this))
		return ;
}

std::ostream &	operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
{
	o << rhs.getName() << ", form grade " << rhs.getGradeS();
	if (rhs.getIsSigned())
		o << " [signed]";
	else
		o << " [not signed]";
	return o;
}

