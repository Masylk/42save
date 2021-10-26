#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

//classe ClapTrap
class	ClapTrap
{
	public :
		//constructeur
		ClapTrap(std::string name);
		//copy constructor
		ClapTrap(ClapTrap const &cpy);
		~ClapTrap();

		//copy operator
		ClapTrap	&operator=(ClapTrap const &rhs);
	
		//Functions
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		//setter
		void    setName(std::string name);
		void    setHitpoints(int hp);
		void    setEnergypoints(int ep);
		void    setAttack_damage(int ad);
		//getter
		std::string	getName() const;
		int    		getHitpoints() const;
		int		getEnergypoints() const;
		int		getAttack_damage() const;
	private :
		std::string	_name;
		int		_hitpoints;
		int		_energypoints;
		int		_attack_damage;
};

#endif
