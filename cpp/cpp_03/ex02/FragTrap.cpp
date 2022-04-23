#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attack_damage = 30;

	std::cout << "FragTrap is built!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap is Destroyed!" << std::endl;
}

/*
 *-------------MEMBER-FUNCTIONS----------
 * */

void	FragTrap::highFivesGuys()
{
	if (this->_hitpoints >= 1)
	{
		std::cout << this->getName() << " wants to make a high five with you !" << std::endl;
	}
	else
		std::cout << this->_name << " is unable to act !" << std::endl;
}
