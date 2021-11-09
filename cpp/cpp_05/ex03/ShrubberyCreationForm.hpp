#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm : public virtual Form
{
	public :
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		virtual	~ShrubberyCreationForm();

		const ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &cpy);
		
		//methods
		virtual void	execute(Bureaucrat const &executor) const;
		virtual	Form	*factoryForm(std::string target);
		//functions
		ShrubberyCreationForm	&beSigned(const Bureaucrat &b);
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

std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm &rhs);

#endif
