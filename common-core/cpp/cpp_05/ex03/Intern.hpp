#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Form;

class	Intern
{
	public :
		Intern();
		Intern(const Intern &cpy);
		~Intern();
		
		//assign operator
		const Intern &operator=(const Intern &rhs);

		//member functions
		Form	*makeForm(std::string form, std::string target);
	private :
		typedef	struct	s_forms
		{
			std::string	name;
			Form		*ptr;
		}		t_forms;
		t_forms	forms[3];
};

#endif
