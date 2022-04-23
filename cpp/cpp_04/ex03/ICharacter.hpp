#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class	AMateria;

class ICharacter
{
	public :
		virtual ~ICharacter() {};
		virtual	std::string const &getName() const = 0;
		virtual	void equip(AMateria *m) = 0;
		virtual	void use(int idc, ICharacter &target) = 0;
		virtual void	unequip(int idx) = 0;
};

class Character : public virtual ICharacter
{
	public :
		Character(std::string const &type);
		//copy constructor
		Character(Character const &cpy);
		~Character();

		//operator copy
		Character const &operator=(Character const &rhs);
		
		//getter
		std::string const	&getName() const;
		//methods
		void		equip(AMateria *m);
		void		unequip(int idx);
		void		use(int idx, ICharacter & target);

	protected :
		std::string	name;
		AMateria	*materias[4];
};

#endif
