#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog is dead" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof !!!" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return this->brain;
}
