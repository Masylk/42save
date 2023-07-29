#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attack_damage = 20;
	this->_gatek_mode = false;

	std::cout << "Scavtrap is built!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cpy): ClapTrap(cpy)
{}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap is Destroyed!" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
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

void	ScavTrap::guardGate()
{
	if (this->_hitpoints >= 1)
	{
		std::cout << this->getName() << " is in gate keeper mode!" << std::endl;
		this->set_gatekmode(true);
	}
	else
		std::cout << this->_name << " is unable to act !" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_energypoints >= 1 && this->_hitpoints >= 1)
	{
		std::cout << "ScavTrap " << this->getName()
			<< " attack " << target << " causing "
			<< this->getAttack_damage() << " points of damage!"
			<< std::endl;
		this->_energypoints--;
	}
	else
		std::cout << this->_name << " is unable to act !" << std::endl;
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

