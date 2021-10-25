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
	std::string	names[10] = {"Mickael", "Soul", "Jamil", "Federico", "Giuseppe", "Carlo", "Mary", "Jolly", "Pablo", "Tara"};

	(void)name;
	srand(time(NULL));	
	i = 0;
	tab =new Zombie[N];
	if (!tab)
		return (NULL);
	while (i < N)
	{ 
		tab[i].setName(names[rand() % 10]);
		i++;
	}
	return (tab);
}
