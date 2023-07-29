#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
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
		virtual void	execute(Bureaucrat const &executor) const  = 0;
		//functions
		virtual Form	&beSigned(const Bureaucrat &b);
		static	bool	isExecutable(const Bureaucrat &b, const Form &f);
		//getters
		virtual const std::string	getName(void) const;
		virtual int		getGradeEx(void) const;
		virtual int		getGradeS(void) const;
		virtual bool		getIsSigned(void) const;
		//exceptions
	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Form Grade too High !");
			}
	};
	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Form Grade too Low !");
			}
	};
	class	NotSignedException : public std::exception
	{
		public :
			virtual const char	*what() const throw()
			{
				return ("Form is not signed !");
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
