#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public :
		//constructeur
		DiamondTrap(std::string name);
		//copy constructor
		DiamondTrap(DiamondTrap const &cpy);
		virtual ~DiamondTrap();
};

#endif
