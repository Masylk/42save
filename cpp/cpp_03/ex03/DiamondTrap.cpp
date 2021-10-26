#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap{name}, FragTrap{name}, ScavTrap{name}
{
	std::cout << "DiamondTrap is built !" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap is destroyed !" << std::endl;
}
