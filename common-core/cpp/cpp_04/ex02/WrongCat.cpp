#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat created" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &cpy): WrongAnimal(cpy)
{}

WrongCat const &	WrongCat::operator=(WrongCat const & rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}


void	WrongCat::makeSound() const
{
	std::cout << "WroooongNyaaaa !" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is dead" << std::endl;
}
