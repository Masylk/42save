#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy)
{
	this->type = cpy.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal is dead" << std::endl;
}


WrongAnimal const &	WrongAnimal::operator=(WrongAnimal const & rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wroooong !" << std::endl;
}
		
std::string	WrongAnimal::getType(void) const
{
	return this->type;
}
