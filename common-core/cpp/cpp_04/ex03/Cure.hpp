#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;
class Cure : public virtual AMateria
{
	public :
		Cure();
		//copy constructor
		Cure(Cure const &cpy);
		~Cure();

		//operator copy
		Cure const &operator=(Cure const &rhs);
		
		//getter
		std::string const	&getType() const;
		//methods
		Cure		*clone(void) const;
		void		use(ICharacter& target);

	protected :
		std::string	type;
};

#endif
