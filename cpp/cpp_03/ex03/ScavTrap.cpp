#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap{name}
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attack_damage = 20;
	this->_gatek_mode = false;

	std::cout << "Scavtrap is built!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap is Destroyed!" << std::endl;
}

/*
 *-------------MEMBER-FUNCTIONS----------
 * */

void	ScavTrap::guardGate()
{
	std::cout << this->getName() << " is in gate keeper mode!" << std::endl;
	this->set_gatekmode(true);
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << this->getName()
		<< " ScavTrap attack " << target << " causing "
		<< this->getAttack_damage() << " points of damage!"
		<< std::endl;
}

/*
 *-------------SETTER/GETTER----------
 * */

bool	ScavTrap::get_gatekmode()
{
	return this->_gatek_mode;
}

void	ScavTrap::set_gatekmode(bool i)
{
	this->_gatek_mode = i;
}

