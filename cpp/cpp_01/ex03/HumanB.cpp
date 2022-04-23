#include "HumanB.hpp"

HumanB::HumanB()
:	_weapon()
{}

HumanB::HumanB(std::string name)
	:	_name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
