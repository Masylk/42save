#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "Dog.hpp"

class	WrongCat: virtual public Dog
{
	public :
		WrongCat();
		WrongCat(WrongCat const &cpy);
		~WrongCat();

		WrongCat const &operator=(WrongCat const &rhs);

		//member functions
		void	makeSound(void) const;
};

#endif
