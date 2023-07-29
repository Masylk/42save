#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &cpy) : AMateria(cpy)
{
	this->type = cpy.type;
}

Ice::~Ice()
{

}

std::string const	&Ice::getType() const
{
	return this->type;
}

Ice const &Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

//methods

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *" << std::endl;
}

Ice		*Ice::clone(void) const
{
	return new Ice(*this);
}
