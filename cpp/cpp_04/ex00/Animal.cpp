#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(Animal const &cpy)
{
	this->type = cpy.type;
}

Animal::~Animal()
{
	std::cout << "Animal is dead" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal" << std::endl;
}
		
std::string	Animal::getType(void) const
{
	return this->type;
}
