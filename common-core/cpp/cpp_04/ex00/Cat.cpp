#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &cpy): Animal(cpy)
{}


Cat::~Cat()
{
	std::cout << "Cat is dead" << std::endl;
}

Cat const &	Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}


void	Cat::makeSound() const
{
	std::cout << "Nyaaaa~ !" << std::endl;
}
