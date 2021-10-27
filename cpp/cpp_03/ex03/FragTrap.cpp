#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap{name}
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
	std::cout << this->getName() << " wants to make a high five with you !" << std::endl;
}

int	FragTrap::getHitpoints(void) const
{
	return this->_hitpoints;
}

int	FragTrap::getAttack_damage(void) const
{
	return this->_attack_damage;
}
