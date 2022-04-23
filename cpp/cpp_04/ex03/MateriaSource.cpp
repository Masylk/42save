#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
		this->learnedMaterias[i++] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &cpy) : IMateriaSource(cpy)
{

	int	i;

	i = 0;
	if (this != &cpy)
	{
		while (i < 4)
			delete this->learnedMaterias[i++];
		i = 0;
		while (i < 4)
		{
			this->learnedMaterias[i] = cpy.learnedMaterias[i];
			i++;
		}
	}
}

MateriaSource::~MateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
		delete this->learnedMaterias[i++];
}

void		MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	while (i < 4 && this->learnedMaterias[i])
		i++;
	if (i < 4)
		this->learnedMaterias[i] = m;
	else
		delete m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i;

	i = 0;
	while (i < 4 && this->learnedMaterias[i] && this->learnedMaterias[i]->getType() != type)
		i++;
	if (i < 4 && this->learnedMaterias[i])
		return this->learnedMaterias[i]->clone();
	std::cout << "No materia found !" << std::endl;
	return NULL;
}

