#include "Karen.hpp"

Karen::Karen()
{
	this->klevels[0] = &Karen::debug;
	this->klevels[1] = &Karen::info;
	this->klevels[2] = &Karen::warning;
	this->klevels[3] = &Karen::error;
}

Karen::Karen(std::string filter)
{
	int	i = 0;

	while (!this->keys[i].empty()
		&& this->keys[i] != filter)
		i++;
	this->filter = i;
	this->klevels[0] = &Karen::debug;
	this->klevels[1] = &Karen::info;
	this->klevels[2] = &Karen::warning;
	this->klevels[3] = &Karen::error;
}

void	Karen::complain(std::string level)
{
	int	i = 0;

	while (!this->keys[i].empty()
		&& this->keys[i].find(level) == std::string::npos)
		i++;
	if (i > 3)
		std::cout << "[BAD LEVEL]" << std::endl;
	else
	{
		switch (this->filter > i)
		{
			case true :
				break;
			default :
				(this->*klevels[i])();
		}
	}
}

void		Karen::debug(void)
{
	std::cout << std::endl << "[DEBUG] : I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it !" << std::endl;
}

void		Karen::info(void)
{
	std::cout << std::endl << "[INFO] : I cannot believe adding extra bacon cost more money. You don't put enough !" << std::endl;
}

void		Karen::warning(void)
{
	std::cout << std::endl << "[WARNING] : I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl;
}

void		Karen::error(void)
{
	std::cout << std::endl << "[ERROR] : This is unacceptable, I want to speak to the manager now." << std::endl;
}

Karen::~Karen()
{
}

