#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <stdlib.h>
# include <time.h>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	RobotomyRequestForm : public virtual Form
{
	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		virtual	~RobotomyRequestForm();

		const RobotomyRequestForm	&operator=(const RobotomyRequestForm &cpy);
		
		//methods
		virtual void	execute(Bureaucrat const &executor) const;
		virtual	Form	*factoryForm(std::string target);
		//functions
		RobotomyRequestForm	&beSigned(const Bureaucrat &b);
		//getters
		const std::string	getName(void) const;
		int		getGradeEx(void) const;
		int		getGradeS(void) const;
		bool		getIsSigned(void) const;
		const std::string	getTarget(void) const;
		//exceptions
	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Bureaucrat Grade too High !");
			}
	};
	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Bureaucrat Grade too Low !");
			}
	};
	private :
		const int		gradeEx;
		const int		gradeS;
		const std::string	name;
		const std::string	target;
		bool			isSigned;
};

std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm &rhs);

#endif
