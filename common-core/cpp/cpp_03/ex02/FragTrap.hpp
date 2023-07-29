#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public :
		FragTrap(std::string const name);
		FragTrap(FragTrap const &cpy);
		~FragTrap();

		FragTrap &operator=(FragTrap const & rhs);
		void	highFivesGuys(void);
};

#endif
