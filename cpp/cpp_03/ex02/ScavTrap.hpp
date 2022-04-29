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

		ScavTrap &operator=(ScavTrap const & rhs);
		
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
