#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat: virtual public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(WrongCat const &cpy);
		~WrongCat();

		WrongCat const &operator=(WrongCat const &rhs);
		void	makeSound(void) const;
};

#endif
