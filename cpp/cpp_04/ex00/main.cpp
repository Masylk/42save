#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	std::cout << "<---------------------" << std::endl;
	const Animal* j = new Dog();
	std::cout << "<---------------------" << std::endl;
	const Animal* i = new Cat();
	std::cout << "<---------------------" << std::endl;
	const Animal* h = new WrongCat();

	std::cout << "<---------------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << "<---------------------" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "<---------------------" << std::endl;
	meta->makeSound();
	std::cout << "<---------------------" << std::endl;
	std::cout << h->getType() << " " << std::endl;
	h->makeSound(); //will output the cat sound!
	std::cout << "<---------------------" << std::endl;
	delete i;
	std::cout << "<---------------------" << std::endl;
	delete j;
	std::cout << "<---------------------" << std::endl;
	delete h;
	std::cout << "<---------------------" << std::endl;
	delete meta;
	std::cout << "<---------------------" << std::endl;
}
