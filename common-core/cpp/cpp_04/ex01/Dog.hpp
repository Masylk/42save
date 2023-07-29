#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: virtual public Animal
{
	public :
		Dog();
		Dog(Dog const &cpy);
		virtual ~Dog();

		Dog const &operator=(Dog const &rhs);

		//member functions
		void	makeSound(void) const;
		Brain	*getBrain(void) const;

	private :
		Brain	*brain;
};

#endif
