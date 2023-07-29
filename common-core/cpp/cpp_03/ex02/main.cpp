#include "ScavTrap.hpp"
#include "FragTrap.hpp"
//main de test pour montrer la fonctionalité du code

int	main()
{
	ClapTrap	jon("Jon");
	ScavTrap	Oly("Oly");
	FragTrap	Berry("Berry");

	Berry.highFivesGuys();
	Oly.attack("your dad");
	Oly.beRepaired(3);
	Oly.takeDamage(5);
	Oly.guardGate();
	jon.attack("your mom");
	jon.beRepaired(3);
	jon.takeDamage(5);
}
