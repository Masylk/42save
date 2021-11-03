#include "Form.hpp"

	Form::Form(std::string name, int gradeEx, int gradeS) : gradeEx(gradeEx)
	, gradeS(gradeS)
			, name(name)
{
	this->isSigned = false;
	if (gradeEx < 1 || gradeS < 1)
		throw Form::GradeTooHighException();
	else if (gradeEx > 150 || gradeS > 150)
		throw Form::GradeTooLowException();
}

	Form::Form(const Form &cpy) : gradeEx(cpy.getGradeEx())
	, gradeS(cpy.getGradeS())
				 , name(cpy.getName())
{
	*this = cpy;
}

Form::~Form()
{

}

//assign operator
const Form &Form::operator=(const Form &rhs)
{
	this->isSigned = rhs.getIsSigned();
	return *this;
}

//getter
const std::string	Form::getName(void) const
{
	return this->name;
}

int			Form::getGradeEx(void) const
{
	return this->gradeEx;
}

int			Form::getGradeS(void) const
{
	return this->gradeS;
}

bool		Form::getIsSigned(void) const
{
	return this->isSigned;
}

Form	&Form::beSigned(const Bureaucrat &b)
{
	try
	{
		if (this->gradeS < b.getGrade())
			throw Form::GradeTooLowException();
		else
			this->isSigned = true;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << ", form grade " << rhs.getGradeS();
	if (rhs.getIsSigned())
		o << " [signed]";
	else
		o << " [not signed]";
	return o;
}

