#include "AMateria.hpp"

AMateria::Amateria(std::string const &type)
{
	this->type = type;
}

AMateria::Amateria(Amateria const &cpy)
{
	this->type = cpy.type;
}

AMateria::~AMateria()
{

}

std::string const	&AMateria() const
{
	return this->type;
}

AMateria const &Amateria::operator=(Amateria const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}
