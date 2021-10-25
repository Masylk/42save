#include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie *stack;
	int		i;
	int		N;
	
	N = 6;
	i = 0;
	stack = zombieHorde(N, "Horde");
	if (!stack)
		return (0);
	while (i < N)
	{
		stack[i].announce();
		i = i + 1;
	}
	i = 0;
	delete[] stack;
}
