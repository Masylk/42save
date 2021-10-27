#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog is dead" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof !!!" << std::endl;
}
