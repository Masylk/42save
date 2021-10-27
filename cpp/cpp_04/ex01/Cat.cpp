#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat is dead" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Nyaaaa~ !" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return this->brain;
}
