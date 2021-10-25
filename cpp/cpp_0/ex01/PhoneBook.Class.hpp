#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>

class Contact
{
	public :

		Contact(void);
		~Contact(void);
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook
{
	public :

		PhoneBook(void);
		~PhoneBook(void);
		int		max_contact;
		int		nb_contact;
		Contact		contacts[9];
};

#endif
