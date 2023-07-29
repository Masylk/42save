#ifndef KAREN_HPP
# define kAREN_HPP

# include <iostream>
# include <iomanip>

class	Harl
{
	public:
		Harl();
		Harl(std::string);
		~Harl();
		void		complain(std::string level);
		int		filter;
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
