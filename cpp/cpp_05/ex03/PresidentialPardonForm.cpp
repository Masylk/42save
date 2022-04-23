#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 5 , 25)
, gradeEx(5), gradeS(25), name("PresidentialPardonForm"), target(target)
{
	this->isSigned = false;
	if (gradeEx < 1 || gradeS < 1)
		throw PresidentialPardonForm::GradeTooHighException();
	else if (gradeEx > 150 || gradeS > 150)
		throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : Form(cpy.getName(), cpy.getGradeEx()
	, cpy.getGradeS()), gradeEx(cpy.getGradeEx()), gradeS(cpy.getGradeS()), name(cpy.getName()), target(cpy.getTarget())
{
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

Form	*PresidentialPardonForm::factoryForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

//assign operator
const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	this->isSigned = rhs.getIsSigned();
	return *this;
}

//getter
const std::string	PresidentialPardonForm::getName(void) const
{
	return this->name;
}

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return this->target;
}

int			PresidentialPardonForm::getGradeEx(void) const
{
	return this->gradeEx;
}

int			PresidentialPardonForm::getGradeS(void) const
{
	return this->gradeS;
}

bool		PresidentialPardonForm::getIsSigned(void) const
{
	return this->isSigned;
}

PresidentialPardonForm	&PresidentialPardonForm::beSigned(const Bureaucrat &b)
{
	try
	{
		if (this->gradeS < b.getGrade())
			throw PresidentialPardonForm::GradeTooLowException();
		else
			this->isSigned = true;
	}
	catch (PresidentialPardonForm::GradeTooLowException e)
	{
		std::cout << e.what();
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (isExecutable(executor, *this))
	{
		std::cout << this->target
			<< " has been forgiven by Zafod Beeblebrox !" << std::endl;
	}
}

std::ostream &	operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
	o << rhs.getName() << ", signing grade " 
		<< rhs.getGradeS() << ", execution grade " << rhs.getGradeEx();
	if (rhs.getIsSigned())
		o << " [signed]";
	else
		o << " [not signed]";
	return o;
}
