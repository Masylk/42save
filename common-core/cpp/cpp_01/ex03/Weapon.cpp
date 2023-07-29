#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
	:	_type(type)
{
}

Weapon::~Weapon()
{
}

std::string	const& Weapon::getType()
{
	return (this->_type);
}

void		Weapon::setType(const std::string &type)
{
	this->_type = type;
}
