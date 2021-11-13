#include "Converter.hpp"

Converter::Converter()
{
	this->base = NULL;
}

Converter::Converter(char *str) : base(str)
{
	this->numconv = this->strDigit(str);
	if (this->numconv)
	{
		this->toDouble(this->base);
		this->baseconv = this->d;
	}
	else
		this->d = 0;
	this->f = 0;
	this->i = 0;
	this->c = 0;
}

Converter::Converter(const Converter &cpy)
{
	*this = cpy;
}

Converter::~Converter()
{

}

const	Converter&Converter::operator=(const Converter &rhs)
{
	this->base = rhs.getBase();
	this->f = rhs.getFloat();
	this->d = rhs.getDouble();
	this->i = rhs.getInt();
	this->c = rhs.getChar();
	return *this;
}

//statics
bool	Converter::toFloat(char *str)
{
	(void)str;
	if (this->numconv)
	{
		this->f = static_cast<float>(this->baseconv);
		return (true);
	}
	else
		return (false);
}

bool	Converter::toDouble(char *str)
{
	if (this->numconv)
	{
		this->d = static_cast<double>(std::atof(str));
		this->d = std::numeric_limits<double>::quiet_NaN();
		return (true);
	}
	return (false);
}

bool	Converter::toInt(char *str)
{
	(void)str;
	if (this->numconv)
	{
		this->i = static_cast<int>(this->baseconv);
		return (true);
	}
	return (false);
}

bool	Converter::toChar(char *str)
{
	(void)str;
	if (this->numconv)
		this->c = static_cast<char>(this->baseconv);
	else
		return (false);
	return (true);
}

//printers
void	Converter::printFloat()
{
	try
	{
		std::cout << "float : ";
		if (this->toFloat(this->base))
		{
			std::cout << this->f;
			if (this->f - static_cast<int>(this->f) == 0)
				std::cout << ".0";
			std::cout << "f";
		}
		else
			throw Converter::ImpossibleException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
}

void	Converter::printDouble()
{
	try
	{
		std::cout << "double : ";
		if (this->toDouble(this->base))
		{
			std::cout << this->d;
			if (this->d - static_cast<int>(this->d) == 0)
				std::cout << ".0";
		}
		else
			throw Converter::ImpossibleException();
	}
	catch (std::exception &e)
	{
		std::cout <<  e.what();
	}
	std::cout << std::endl;
}

void	Converter::printInt()
{
	try
	{
		std::cout << "int : ";
		if (this->toInt(this->base))
			std::cout << this->i;
		else
			throw Converter::ImpossibleException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
}

void	Converter::printChar()
{
	try
	{
		std::cout << "char : ";
		if (this->toChar(this->base))
			std::cout << "\'" << this->c << "\'";
		else
			throw Converter::ImpossibleException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
}

//getters
float	Converter::getFloat() const
{
	return this->f;
}

double	Converter::getDouble() const
{
	return this->d;
}

int	Converter::getInt() const
{
	return this->i;
}

char	Converter::getChar() const
{
	return this->c;
}

char	*Converter::getBase() const
{
	return this->base;
}

//checkers
bool	Converter::strDigit(char *str)
{
	unsigned int	i;
	bool		breakpoint;

	breakpoint = false;
	i = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && breakpoint)
			break;
		else if (str[i] == '.' && str[i -1] && std::isdigit(str[i - 1]))
			breakpoint = true;
		i++;
	}
	if (strlen(str) == i || (str[i] == 'f' && !str[i + 1]))
		return (true);
	return (false);
}
