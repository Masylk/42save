#include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int	main(void)
{
	Zombie *stack;

	stack = newZombie("Patrick");
	randomChump("Lionel");
	delete stack;
}
