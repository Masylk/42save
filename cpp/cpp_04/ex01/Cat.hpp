#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: virtual public Animal
{
	public :
		Cat();
		Cat(Cat const &cpy);
		~Cat();

		Cat const &operator=(Cat const &rhs);

		//member functions
		void	makeSound(void) const;
		Brain	*getBrain(void) const;

	private :
		Brain	*brain;

};

#endif
