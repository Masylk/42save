#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat created" << std::endl;
	this->type = "WrongCat";
}

void	WrongCat::makeSound() const
{
	std::cout << "WroooongNyaaaa !" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is dead" << std::endl;
}
