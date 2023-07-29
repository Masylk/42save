#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(Animal const &cpy)
{
	std::cout << "animal copy" << std::endl;
	this->type = cpy.type;
}

Animal::~Animal()
{
	std::cout << "Animal is dead" << std::endl;
}

void	Animal::makeSound() const
{}
		
Animal const &Animal::operator=(Animal const &rhs)
{
	std::cout << "animal operator";
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::string	Animal::getType(void) const
{
	return this->type;
}
