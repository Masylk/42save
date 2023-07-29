#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
	public :
		AMateria(std::string const &type);
		//copy constructor
		AMateria(AMateria const &cpy);
		virtual ~AMateria();

		//operator copy
		AMateria const &operator=(Amateria const &rhs);
		
		//getter
		std::string const	&getType() const = 0;
		//methods
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter& target) = 0;

	protected :
		std::string	type;
};

#endif
