#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 45 , 72)
, gradeEx(45), gradeS(72), name("RobotomyRequestForm"), target(target)
{
	this->isSigned = false;
	if (gradeEx < 1 || gradeS < 1)
		throw RobotomyRequestForm::GradeTooHighException();
	else if (gradeEx > 150 || gradeS > 150)
		throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : Form(cpy.getName(), cpy.getGradeEx()
	, cpy.getGradeS()), gradeEx(cpy.getGradeEx()), gradeS(cpy.getGradeS()), name(cpy.getName()), target(cpy.getTarget())
{
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

//assign operator
const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	this->isSigned = rhs.getIsSigned();
	return *this;
}

//getter
const std::string	RobotomyRequestForm::getName(void) const
{
	return this->name;
}

const std::string	RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

int			RobotomyRequestForm::getGradeEx(void) const
{
	return this->gradeEx;
}

int			RobotomyRequestForm::getGradeS(void) const
{
	return this->gradeS;
}

bool		RobotomyRequestForm::getIsSigned(void) const
{
	return this->isSigned;
}

RobotomyRequestForm	&RobotomyRequestForm::beSigned(const Bureaucrat &b)
{
	try
	{
		if (this->gradeS < b.getGrade())
			throw RobotomyRequestForm::GradeTooLowException();
		else
			this->isSigned = true;
	}
	catch (RobotomyRequestForm::GradeTooLowException e)
	{
		std::cout << e.what();
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (isExecutable(executor, *this))
	{
		srand(time(NULL));
		if (rand() % 2 >= 1)
			std::cout << this->target << " has been robotomized !" << std::endl;
		else
			std::cout << this->target << " failed robotomization !" << std::endl;
	}
}

std::ostream &	operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
	o << rhs.getName() << ", signing grade " 
		<< rhs.getGradeS() << ", execution grade " << rhs.getGradeEx();
	if (rhs.getIsSigned())
		o << " [signed]";
	else
		o << " [not signed]";
	return o;
}
