#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &cpy): Animal(cpy)
{}

Dog::~Dog()
{
	std::cout << "Dog is dead" << std::endl;
}

Dog const &	Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}


void	Dog::makeSound() const
{
	std::cout << "Woof !!!" << std::endl;
}
