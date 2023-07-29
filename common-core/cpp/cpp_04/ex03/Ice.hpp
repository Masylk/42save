#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;
class Ice : public virtual AMateria
{
	public :
		Ice();
		//copy constructor
		Ice(Ice const &cpy);
		~Ice();

		//operator copy
		Ice const &operator=(Ice const &rhs);
		
		//getter
		std::string const	&getType() const;
		//methods
		Ice		*clone(void) const;
		void		use(ICharacter& target);

	protected :
		std::string	type;
};

#endif
