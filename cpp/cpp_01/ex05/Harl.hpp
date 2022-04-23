#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <iomanip>

class	Harl
{
	public:
		Harl();
		~Harl();
		void		complain(std::string level);
	private:
		typedef void 	(Harl::*levels)(void);
		levels		klevels[4];
		std::string	keys[4];
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
};

#endif
