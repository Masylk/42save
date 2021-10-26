#include "Fixed.hpp"


/*
 * ------------------------CONSTRUCTORS--------------------------------
 * */
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
	this->value = roundf(val * (1 << this->bits));
}

Fixed::Fixed(Fixed const & cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = cpy.getRawBits();
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/*
 * --------------------SETTERS/GETTERS--------------------------------
 * */

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

/*
 * ------------------------OPERATORS--------------------------------
 * */

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

/*
 * ------------------------------COMPARISON--------------------------------
 * */

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(Fixed const & rhs) const
{	
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{	
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{	
	return (this->toFloat() != rhs.toFloat());
}

/*
 * ------------------------------ARITHMETIC--------------------------------
 * */

Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed ret(*this);
	long	tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)rhs.getRawBits());
	ret.setRawBits((tmp1 * tmp2) / (1 << Fixed::bits));
	return ret;
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed	ret(*this);

	ret.setRawBits(this->getRawBits() + rhs.getRawBits());
	return ret;
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	Fixed	ret(*this);

	ret.setRawBits(this->getRawBits() - rhs.getRawBits());
	return ret;
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed	ret(*this);

	ret.setRawBits((this->getRawBits() * (1 << this->bits)) / rhs.getRawBits());
	return ret;
}

/*
 * ------------------------CONVERSIONS--------------------------------
 * */

//conver Fixed to Int
int	Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

//convert Fixed to Float
float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << (this->bits)));
}

/*
 * ------------------------INCREMENT/DECREMENT--------------------------------
 * */

Fixed	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	operator--();
	return (tmp);
}

/*
 * ------------------------INCREMENT/DECREMENT--------------------------------
 * */

Fixed 		&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (rhs);
	return (lhs);
}

const Fixed 	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return (rhs);
	return (lhs);
}

Fixed 		&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

const Fixed 	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}
