#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	Animal *arr[10];
	int	i;
	
	i = 0;
	while (i < 10)
	{
		std::cout << i << "<---------------------" << std::endl;
		if (i < 5)
		{
			arr[i] = new Dog();
		}
		else
			arr[i] = new Cat();
		i++;
	}
	i = 0;
	while (i < 10)
	{
		std::cout << i << "<---------------------" << std::endl;
		delete arr[i++];
	}
}
