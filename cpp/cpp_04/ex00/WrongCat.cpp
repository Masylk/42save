#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat created" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is dead" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Nyaaaa~ !" << std::endl;
}
