#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	public :
		Animal();
		Animal(Animal const &cpy);
		virtual ~Animal();

		Animal const &operator=(Animal const &rhs);

		//member functions
		virtual void	makeSound(void) const;
		
		std::string	getType(void) const;
	protected :
		std::string	type;
};

#endif
