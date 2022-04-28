#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	public :
		WrongAnimal();
		WrongAnimal(WrongAnimal const &cpy);
		virtual ~WrongAnimal();

		WrongAnimal const &operator=(WrongAnimal const &rhs);

		//member functions
		void	makeSound(void) const;
		
		std::string	getType(void) const;
	protected :
		std::string	type;
};

#endif
