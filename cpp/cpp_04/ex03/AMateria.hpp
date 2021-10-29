#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;
class AMateria
{
	public :
		AMateria(std::string const &type);
		//copy constructor
		AMateria(AMateria const &cpy);
		virtual ~AMateria();

		//operator copy
		AMateria const &operator=(AMateria const &rhs);
		
		//getter
		std::string const	&getType() const;
		//methods
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter& target);

	protected :
		std::string	type;
};

#endif
