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

Animal const &Animal::operator=(Animal const &rhs)
{
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
