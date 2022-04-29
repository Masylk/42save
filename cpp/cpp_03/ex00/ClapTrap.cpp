#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << " is built !" << std::endl;
	this->_name = name;
	this->_energypoints = 10;
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

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
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
 *---------------FUNCTIONS------------
 **/

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energypoints >= 1 && this->_hitpoints >= 1)
	{
		std::cout << "ClapTrap " << this->getName()
			<< " attack " << target << " causing "
			<< this->getAttack_damage() << " points of damage!"
			<< std::endl;
		this->_energypoints--;
	}
	else
		std::cout << this->_name << " is unable to act !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName()
		<< " loses " << amount << " hitpoints!"
		<< std::endl;
	this->_hitpoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energypoints >= 1 && this->_hitpoints >= 0)
	{
		std::cout << "ClapTrap " << this->getName()
			<< " is repaired for " << amount << " hitpoints!"
			<< std::endl;
		this->_hitpoints += amount; 
		this->_energypoints--;
	}
	else
		std::cout << this->_name << " is unable to act !" << std::endl;
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
