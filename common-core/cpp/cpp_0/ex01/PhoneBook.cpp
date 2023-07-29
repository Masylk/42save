#include "PhoneBook.Class.hpp"

PhoneBook::PhoneBook(void)
{
	this->max_contact = 8;
	this->nb_contact = 0;
	this->oldest_contact = 0;
}

PhoneBook::~PhoneBook(void)
{
}


int	PhoneBook::get_max_contact()
{
	return this->max_contact;
}

int	PhoneBook::get_nb_contact()
{
	return this->nb_contact;
}

int	PhoneBook::get_oldest_contact()
{
	return this->oldest_contact;
}

Contact	*PhoneBook::get_contact(int index)
{
	return &(this->contacts[index]);
}

void	PhoneBook::set_nb_contact(int i)
{
	this->nb_contact = i;
}

void	PhoneBook::add_contact(int index, Contact entry)
{
	this->contacts[index] = entry;
}

void	PhoneBook::set_oldest_contact(int i)
{
	this->oldest_contact = i;
}
