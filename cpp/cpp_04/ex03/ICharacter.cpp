#include "ICharacter.hpp"

Character::Character(std::string const &name)
{
	this->materias[0] = NULL;
	this->materias[1] = NULL;
	this->materias[2] = NULL;
	this->materias[3] = NULL;
	this->name = name;
}

Character::Character(Character const &cpy)
{
	int	i;

	i = 0;
	if (this != &cpy)
	{
		while (i < 4)
			delete this->materias[i++];
		i = 0;
		while (i < 4)
		{
			this->materias[i] = cpy.materias[i];
			i++;
		}
		this->name = cpy.name;
	}
}

Character::~Character()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		delete this->materias[i++];
	}
}

Character const &Character::operator=(Character const &rhs)
{
	int	i;

	i = 0;
	while (i < 4)
		delete this->materias[i++];
	i = 0;
	while (i < 4)
	{
		this->materias[i] = rhs.materias[i];
		i++;
	}
	this->name = rhs.name;
	return *this;
}

std::string const 	&Character::getName() const
{
	return this->name;
}

/*
 *-----------------MEMBER-FUNCTION-------------
 * */

void		Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	while (this->materias[i] && i < 4)
		i++;
	if (i >= 4)
		return ;
	else
		this->materias[i] = m;
}

void		Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->materias[idx])
	{
		delete this->materias[idx];
		this->materias[idx] = NULL;
	}
}

void		Character::use(int idx, ICharacter & target)
{
	if (idx >= 0 && idx < 4 && this->materias[idx])
		this->materias[idx]->use(target);
}
