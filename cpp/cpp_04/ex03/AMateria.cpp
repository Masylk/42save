#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(AMateria const &cpy)
{
	this->type = cpy.type;
}

AMateria::~AMateria()
{
}

std::string const	&AMateria::getType() const
{
	return this->type;
}

AMateria const &AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

//methods

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
