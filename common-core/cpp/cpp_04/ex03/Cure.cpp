#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &cpy) : AMateria(cpy)
{
	this->type = cpy.type;
}

Cure::~Cure()
{

}

std::string const	&Cure::getType() const
{
	return this->type;
}

Cure const &Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

//methods

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals  " << target.getName()
		<< "'s wounds *" << std::endl;
}

Cure		*Cure::clone(void) const
{
	return new Cure(*this);
}
