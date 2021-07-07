#include <iostream>
#include <iomanip>
#include "PhoneBook.Class.hpp"

void	aff_line(std::string index, std::string f_name, std::string l_name, std::string n_name)
{

	std::cout << std::setw(10);
	std::cout << index;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << f_name;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << l_name;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << n_name;
	std::cout << std::endl;
}

void	aff_contact(Contact contact)
{
	std::cout << "First name : " << contact.first_name << std::endl;
	std::cout << "Last name : " << contact.last_name << std::endl;
	std::cout << "Phone number : " << contact.phone_number << std::endl;
	std::cout << "Nickname : " << contact.nickname << std::endl;
	std::cout << "Darkest secret : " << contact.darkest_secret << std::endl;
}

int	aff_contacts(PhoneBook pbook)
{
	int				i;
	Contact				contact;
	std::string			s_index;
	std::string::const_iterator	it;
	
	i = 0;
	aff_line("index", "first_name", "last_name", "nickname");
	while (!pbook.contacts[i].first_name.empty())
	{
		contact = pbook.contacts[i];
		aff_line(std::to_string(i), contact.first_name,
				contact.last_name, contact.nickname);
		i++;
	}
	std::cout << "Which index would you like to consult ? : ";
	std::cin >> s_index;
	it = s_index.begin();
	while (it != s_index.end())
	{
		if (!std::isdigit(*it))
		{
			std::cout << "Bad format" << std::endl;
			return (0);
		}
		it++;
	}
	if (!pbook.contacts[stoi(s_index)].first_name.empty())
		aff_contact(pbook.contacts[stoi(s_index)]);
	else
		std::cout << "Bad index" << std::endl;
	return (1);
}

int	add_contact(PhoneBook *pbook)
{
	if (pbook->nb_contact >= pbook->max_contact)
	{
		std::cout << "can't add more contact" << std::endl;
		return (0);
	}
	std::cout << "Enter first name : ";
	std::cin >> pbook->contacts[pbook->nb_contact].first_name;
	std::cout << "Enter last name : ";
	std::cin >> pbook->contacts[pbook->nb_contact].last_name;
	std::cout << "Enter nick name : ";
	std::cin >> pbook->contacts[pbook->nb_contact].nickname;
	std::cout << "Enter phone number : ";
	std::cin >> pbook->contacts[pbook->nb_contact].phone_number;
	std::cout << "Enter darkest secret : ";
	std::cin >> pbook->contacts[pbook->nb_contact].darkest_secret;
	pbook->nb_contact += 1;
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
		if (!input.compare("ADD"))
			add_contact(&pbook);
		else if (!input.compare("SEARCH"))
			aff_contacts(pbook);
	}
}
