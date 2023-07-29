#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attack_damage = 30;

	std::cout << "FragTrap is built!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap is Destroyed!" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_energypoints = rhs.getEnergypoints();
		this->_hitpoints = rhs.getHitpoints();
		this->_attack_damage = rhs.getAttack_damage();
	}
	return *this;
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
