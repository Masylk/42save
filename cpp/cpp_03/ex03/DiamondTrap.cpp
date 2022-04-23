#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitpoints = 100;
	this->_attack_damage = 30;
	this->_energypoints = 50;
	std::cout << getName() << " DiamondTrap is built !" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap is destroyed !" << std::endl;
}


void	DiamondTrap::whoAmI()
{
	std::cout << "I am : " << this->_name << std::endl;	
	std::cout << "And : " << ClapTrap::_name << std::endl;	
}	
