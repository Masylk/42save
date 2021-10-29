#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat is dead" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Nyaaaa~ !" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy)
{
	this->type = cpy.getType();
	this->brain = new Brain();
	this->brain = cpy.getBrain();
}

Cat const &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		delete this->brain;
		this->brain = new Brain();
		this->brain =  rhs.getBrain();
		this->type = rhs.getType();
	}
	return *this;
}

Brain	*Cat::getBrain(void) const
{
	return this->brain;
}
