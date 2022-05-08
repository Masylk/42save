#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

//classe ScavTrap
//inherits ClapTrap
class	ScavTrap :virtual public ClapTrap
{
	public :
		//constructeur
		ScavTrap(std::string name);
		//copy constructor
		ScavTrap(ScavTrap const &cpy);
		virtual ~ScavTrap();

		//copy operator
		ScavTrap	&operator=(ScavTrap const &rhs);
		
		//Member functions
		void	guardGate();
		void	attack(std::string const &target);

		//setter/getter
		bool	get_gatekmode();
		void	set_gatekmode(bool i);
	protected :
		bool	_gatek_mode;
};

#endif
