#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	public :
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();
		
		//assign operator
		const Bureaucrat &operator=(const Bureaucrat &rhs);

		//getter
		const std::string	getName(void) const;
		int			getGrade(void) const;

		//member functions
		void	upgrade(void);
		void	downgrade(void);
		void	signForm(Form &f);	

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
		const std::string	name;
		int			grade;
};

//print operator
std::ostream	 &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
