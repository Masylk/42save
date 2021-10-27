#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class	Dog: virtual public Animal
{
	public :
		Dog();
		Dog(Dog const &cpy);
		~Dog();

		Dog const &operator=(Dog const &rhs);

		//member functions
		void	makeSound(void) const;
};

#endif
