#ifndef SCAVTRAP_HPP
# define sCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

//classe ScavTrap
//inherits ScavTrap
class	ScavTrap : public ClapTrap
{
	public :
		//constructeur
		ScavTrap(std::string name);
		//copy constructor
		ScavTrap(ScavTrap const &cpy);
		~ScavTrap();

		//Member functions
		void	guardGate();

		//setter/getter
		bool	get_gatekmode();
		void	set_gatekmode(bool i);
	protected :
		bool	_gatek_mode;
};

#endif
