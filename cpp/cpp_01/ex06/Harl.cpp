#include "Harl.hpp"

Harl::Harl()
{
	this->keys[0] = "DEBUG";
	this->keys[1] = "INFO";
	this->keys[2] = "WARNING";
	this->keys[3] = "ERROR";	
	this->klevels[0] = &Harl::debug;
	this->klevels[1] = &Harl::info;
	this->klevels[2] = &Harl::warning;
	this->klevels[3] = &Harl::error;
}

Harl::Harl(std::string filter)
{
	int	i = 0;
	
	this->keys[0] = "DEBUG";
	this->keys[1] = "INFO";
	this->keys[2] = "WARNING";
	this->keys[3] = "ERROR";		
	while (!this->keys[i].empty()
		&& this->keys[i] != filter)
		i++;
	this->filter = i;
	this->klevels[0] = &Harl::debug;
	this->klevels[1] = &Harl::info;
	this->klevels[2] = &Harl::warning;
	this->klevels[3] = &Harl::error;
}

void	Harl::complain(std::string level)
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

void		Harl::debug(void)
{
	std::cout << std::endl << "[DEBUG] : I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void		Harl::info(void)
{
	std::cout << std::endl << "[INFO] : I cannot believe adding extra bacon cost more money. You don't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void		Harl::warning(void)
{
	std::cout << std::endl << "[WARNING] : I think I deserve to have some extra bacon for free. I've been coming for years whereas you just started working here since last month." << std::endl;
}

void		Harl::error(void)
{
	std::cout << std::endl << "[ERROR] : This is unacceptable, I want to speak to the manager now." << std::endl;
}

Harl::~Harl()
{
}

