#include "DiamondTrap.hpp"
//main de test pour montrer la fonctionalité du code

int	main()
{
	ClapTrap	jon("Jon");
	std::cout << "<----------------------" << std::endl;
	ScavTrap	Oly("Oly");
	std::cout << "<----------------------" << std::endl;
	FragTrap	Berry("Berry");
	std::cout << "<----------------------" << std::endl;
	DiamondTrap	Jojo("Jojo");

	std::cout << "<----------------------" << std::endl;
	Jojo.whoAmI();
	Jojo.highFivesGuys();
	Jojo.guardGate();
	std::cout << "AD: " << Jojo.getAttack_damage() << std::endl;
	std::cout << "EP: " << Jojo.getEnergypoints() << std::endl;
	std::cout << "HP: " << Jojo.getHitpoints() << std::endl;
	Jojo.attack("your sister");
	std::cout << "<----------------------" << std::endl;
	Berry.highFivesGuys();
	std::cout << "<----------------------" << std::endl;
	Oly.attack("your dad");
	Oly.beRepaired(3);
	Oly.takeDamage(5);
	Oly.guardGate();
	std::cout << "<----------------------" << std::endl;
	jon.attack("your mom");
	jon.beRepaired(3);
	jon.takeDamage(5);
	std::cout << "<----------------------" << std::endl;
}
