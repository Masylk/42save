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
		virtual void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		//setter
		virtual void    setName(std::string name);
		virtual void    setHitpoints(int hp);
		virtual void    setEnergypoints(int ep);
		virtual void    setAttack_damage(int ad);
		//getter
		virtual std::string	getName() const;
		virtual int    		getHitpoints() const;
		virtual int		getEnergypoints() const;
		virtual int		getAttack_damage() const;
	protected :
		std::string	_name;
		int		_hitpoints;
		int		_energypoints;
		int		_attack_damage;
};

#endif
