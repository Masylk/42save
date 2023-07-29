#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class	IMateriaSource
{
	public :
		virtual ~IMateriaSource(){};
		virtual	void learnMateria(AMateria *m) = 0;
		virtual	AMateria *createMateria(std::string const &type) = 0;
};

class	MateriaSource : public virtual IMateriaSource
{
	public :
		MateriaSource();
		MateriaSource(MateriaSource const &cpy);
		~MateriaSource();
		
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

	protected :
		AMateria	*learnedMaterias[4];
};

#endif
