#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"

int	main()
{
	AMateria	*droppedMaterias[1000];
	int		i = 0;

	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	ICharacter	*me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter	*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(4, *bob);

	droppedMaterias[i++] = tmp;
	me->unequip(1);
	delete bob;
	delete me;
	delete src;
	int	j = i; 
	i = 0;
	while (i < j)
		delete droppedMaterias[i++];
}
