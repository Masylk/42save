#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(std::string const name);
		FragTrap(FragTrap const &cpy);
		virtual ~FragTrap();

		int	getHitpoints(void) const;
		int	getAttack_damage(void) const;
		void	highFivesGuys(void);
};

#endif
