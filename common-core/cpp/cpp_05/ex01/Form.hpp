#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public :
		Form(std::string name, int gradeEx, int gradeS);
		Form(const Form &cpy);
		virtual ~Form();

		const Form	&operator=(const Form &cpy);
		
		//methods
		virtual Form	&beSigned(const Bureaucrat &b);
		//getters
		const std::string	getName(void) const;
		int		getGradeEx(void) const;
		int		getGradeS(void) const;
		bool		getIsSigned(void) const;
		//exceptions
	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Grade too High !");
			}
	};
	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Grade too Low !");
			}
	};
	private :
		const int		gradeEx;
		const int		gradeS;
		const std::string	name;
		bool			isSigned;
};

std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
