#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				av[i][j] = toupper(av[i][j]);
				j++;
			}
			std::cout << av[i];
			i++;
		}
	}
	std::cout << std::endl;	
}
