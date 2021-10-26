#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(std::string const name);
		FragTrap(FragTrap const &cpy);
		virtual ~FragTrap();

		void	highFivesGuys(void);
};

#endif
