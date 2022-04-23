#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "PhoneBook.Class.hpp"

void	aff_line(std::string index, std::string f_name, std::string l_name, std::string n_name)
{

	std::cout << std::setw(10);
	std::cout << index;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << f_name.substr(0, 9);
	if (f_name.length() > 9)
		std::cout << ".";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << l_name.substr(0, 9);
	if (l_name.length() > 9)
		std::cout << ".";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << n_name.substr(0, 9);
	if (n_name.length() > 9)
		std::cout << ".";
	std::cout << std::endl;
}

void	aff_contact(Contact contact)
{
	std::cout << "First name : " << contact.get_first_name() << std::endl;
	std::cout << "Last name : " << contact.get_last_name() << std::endl;
	std::cout << "Phone number : " << contact.get_phone_number() << std::endl;
	std::cout << "Nickname : " << contact.get_nickname() << std::endl;
	std::cout << "Darkest secret : " << contact.get_darkest_secret() << std::endl;
}

int	aff_contacts(PhoneBook pbook)
{
	int				i;
	Contact				*contact;
	std::string			s_index;
	std::string::const_iterator	it;
	std::ostringstream		convert;

	i = 0;
	aff_line("index", "first_name", "last_name", "nickname");
	while (!pbook.get_contact(i)->get_first_name().empty())
	{
		convert << i;
		contact = pbook.get_contact(i);
		aff_line(convert.str(), contact->get_first_name(),
				contact->get_last_name(), contact->get_nickname());
		convert.str("");
		convert.clear();
		i++;
	}
	std::cout << "Which index would you like to consult ? : ";
	std::cin >> s_index;
	it = s_index.begin();
	while (it != s_index.end() && s_index.length() == 1)
	{
		if (!std::isdigit(*it))
		{
			std::cout << "Bad format" << std::endl;
			return (0);
		}
		it++;
	}
	if (s_index.length() == 1)
	{
		int	j;
		std::istringstream(s_index) >> j;
		if (j < pbook.get_max_contact() && !pbook.get_contact(j)->get_first_name().empty())
			aff_contact(*(pbook.get_contact(j)));
		else
			std::cout << "Bad index" << std::endl;
	}
	else
		std::cout << "Bad index" << std::endl;
	return (1);
}

int	add_contact(PhoneBook *pbook)
{
	std::string str;
	
	if (pbook->get_oldest_contact() >= pbook->get_max_contact())
		pbook->set_oldest_contact(0);
	
	std::cout << "Enter first name : ";
	std::cin >> str;
	pbook->get_contact(pbook->get_oldest_contact())->set_first_name(str);
	str.clear();
	std::cout << "Enter last name : ";
	std::cin >> str;
	pbook->get_contact(pbook->get_oldest_contact())->set_last_name(str);
	str.clear();
	std::cout << "Enter nick name : ";
	std::cin >> str;
	pbook->get_contact(pbook->get_oldest_contact())->set_nickname(str);
	str.clear();
	std::cout << "Enter phone number : ";
	std::cin >> str;
	pbook->get_contact(pbook->get_oldest_contact())->set_phone_number(str);
	str.clear();
	std::cout << "Enter darkest secret : ";
	std::cin >> str;
	pbook->get_contact(pbook->get_oldest_contact())->set_darkest_secret(str);
	str.clear();
	
	if (pbook->get_nb_contact() < pbook->get_max_contact())
		pbook->set_nb_contact(pbook->get_nb_contact() + 1);
	pbook->set_oldest_contact(pbook->get_oldest_contact() + 1);
	return (1);	
}

int	main(void)
{
	std::string 	input;
	PhoneBook	pbook;

	while (input.compare("EXIT"))
	{
		input.clear();
		std::cout << "Enter a command : ";
		std::cin >> input;
		if (input.empty())
			break ;
		if (!input.compare("ADD"))
			add_contact(&pbook);
		else if (!input.compare("SEARCH"))
			aff_contacts(pbook);
	}
}
