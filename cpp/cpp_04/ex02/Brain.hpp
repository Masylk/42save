#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	public :
		Brain();
		Brain(Brain const &cpy);
		virtual ~Brain();

		Brain const &operator=(Brain const &rhs);

		std::string*	getIdeas(void) const;
	protected :
		std::string	*ideas;
};

#endif
