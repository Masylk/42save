#ifndef KAREN_HPP
# define kAREN_HPP

# include <iostream>
# include <iomanip>

class	Karen
{
	public:
		Karen();
		Karen(std::string);
		~Karen();
		void		complain(std::string level);
		int		filter;
	private:
		typedef void 	(Karen::*levels)(void);
		levels		klevels[4];
		std::string	keys[4]{ "DEBUG", "INFO", "WARNING", "ERROR" };
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
};

#endif
