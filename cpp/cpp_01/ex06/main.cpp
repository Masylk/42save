//Faire un main de test qui vérifie bien que
//la fonction complain affiche bien le bon message
//selon le niveau (string) demandé
//les niveaux sont stocké dans un tableau de fonction
//allant de 0 à 3 (taille 4)

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "[Probably complaining about insignificant problems]"
			<< std::endl;
		return (0);

	}
	std::string	filter(av[1]);
	Harl		test = Harl(filter);
	if (test.filter > 3)
	{
		std::cout << "[Probably complaining about insignificant problems]"
			<< std::endl;
		return (0);
	}
	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("ERROR");
	test.complain("DBUG");
}
