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

Dog::Dog(Dog const &cpy) : Animal(cpy)
{
	this->type = cpy.getType();
	this->brain = new Brain(*cpy.getBrain());
}

Dog const &Dog::operator=(Dog const &rhs)
{
	std::cout << "oui";
	if (this != &rhs)
	{
		std::cout << "oui";
		delete this->brain;
		this->brain = new Brain();
		*this->brain = *rhs.getBrain();
		//	this->brain->setIdeas(rhs.getBrain()->getIdeas());
		this->type = rhs.getType();
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof !!!" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return this->brain;
}
