#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>

class Contact
{
	public :

		Contact(void);
		~Contact(void);

		std::string	get_first_name();	
		std::string	get_last_name();	
		std::string	get_nickname();	
		std::string	get_phone_number();	
		std::string	get_darkest_secret();

		void		set_first_name(std::string str);	
		void		set_last_name(std::string str);	
		void		set_nickname(std::string str);	
		void		set_phone_number(std::string str);	
		void		set_darkest_secret(std::string str);	

	private :
	
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

		int	get_max_contact();
		int	get_nb_contact();
		int	get_oldest_contact();
		Contact	*get_contact(int index);

		void	set_nb_contact(int i);
		void	set_oldest_contact(int i);
		void	add_contact(int index, Contact entry);

	private :

		int		max_contact;
		int		nb_contact;
		int		oldest_contact;
		Contact		contacts[9];
};

#endif
