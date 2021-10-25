//Faire un main de test qui vérifie bien que
//la fonction complain affiche bien le bon message
//selon le niveau (string) demandé
//les niveaux sont stocké dans un tableau de fonction
//allant de 0 à 3 (taille 4)

#include "Karen.hpp"

int	main()
{
	Karen	test;

	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("ERROR");
	test.complain("DBUG");
}
