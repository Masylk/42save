#include "Zombie.hpp"

Zombie  *newZombie(std::string name)
{
	Zombie  *z;

	z = new Zombie(name);
	return (z);
}

Zombie	*zombieHorde(int N, std::string name)
{
	int	i;
	Zombie	*tab;
	
	i = 0;
	tab =new Zombie[N];
	if (!tab)
		return (NULL);
	while (i < N)
	{ 
		tab[i].setName(name);
		i++;
	}
	return (tab);
}
