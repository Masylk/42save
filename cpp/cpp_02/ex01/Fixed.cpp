#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
	return ;
}

//constructor with int to Fixed conversion
Fixed::Fixed(int const val)
{
	this->value = (val * (1 << this->bits));
}

//constructor with float to Fixed conversion
Fixed::Fixed(float const val)
{
	this->value = floor(0.5 + (val * (1 << this->bits)));
}

Fixed::Fixed(Fixed const & cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

//convert Fixed to Float
float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << (this->bits)));
}

//conver Fixed to Int
int	Fixed::toInt(void) const
{
	return (this->value / (1 << this->bits));
}
