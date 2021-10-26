#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << " is built !" << std::endl;
	this->_name = name;
	this->_energypoints = 0;
	this->_hitpoints = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	std::cout << cpy.getName() << " is copied !" << std::endl;
	this->_name = cpy.getName();
	this->_energypoints = cpy.getEnergypoints();
	this->_hitpoints = cpy.getHitpoints();
	this->_attack_damage = cpy.getAttack_damage();
}

ClapTrap::~ClapTrap()
{
	std::cout << this->getName() << " is destroyed !" << std::endl;
}

/*
 *---------------FUNCTIONS------------
 **/

void	ClapTrap::attack(std::string const &target)
{
	std::cout << this->getName()
		<< " attack " << target << " causing "
		<< this->getAttack_damage() << " points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->getName()
		<< " loses " << amount << " hitpoints!"
		<< std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->getName()
		<< " is repaired for " << amount << " hitpoints!"
		<< std::endl;
}

/*
 *---------------GETTER------------
 **/
std::string	ClapTrap::getName() const
{
	return this->_name;
}

int	ClapTrap::getHitpoints() const
{
	return this->_hitpoints;
}

int	ClapTrap::getEnergypoints() const
{
	return this->_energypoints;
}

int	ClapTrap::getAttack_damage() const
{
	return this->_attack_damage;
}

/*
 *---------------SETTER------------
 **/

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitpoints(int hp)
{
	this->_hitpoints = hp;
}

void	ClapTrap::setEnergypoints(int ep)
{
	this->_energypoints = ep;
}

void	ClapTrap::setAttack_damage(int ad)
{
	this->_attack_damage = ad;
}
