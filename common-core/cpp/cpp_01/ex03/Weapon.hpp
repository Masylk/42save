#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>

class	Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		std::string	const &getType();
		void		setType(const std::string& type);		
	private:
		std::string	_type;
};

#endif
