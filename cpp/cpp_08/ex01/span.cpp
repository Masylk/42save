#include "span.hpp"

Span::Span(unsigned int n) : size(n)
{
	v.reserve(n);
}

Span::Span(const Span &cpy)
{
	this->v.reserve(cpy.getSize());
	this->size = cpy.getSize();

	copy(cpy.v.begin(), cpy.v.end(), back_inserter(this->v));
}

Span::~Span()
{

}

const Span	&Span::operator=(const Span &rhf)
{
	if (this != &rhf)
	{
		this->v.reserve(rhf.getSize());
		this->size = rhf.getSize();
		
		copy(rhf.v.begin(), rhf.v.end(), back_inserter(this->v));
	}
	return *this;
}

void		Span::addNumber(int n)
{
	if (this->v.size() < this->size)
	{
		this->v.push_back(n);
	}
	else
		throw MaxCapacityException();
}

long		Span::longestSpan()
{
	long	max;
	long	min;

	if (v.size() <= 1)
		throw NoSpanException();
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (it == v.begin())
		{
			min = *it;
			max = *it;
		}
		if (min > *it)
			min = *it;
		if (max < *it)
			max = *it;
	}
	return (static_cast<long>(max) - static_cast<long>(min));
}

long		Span::shortestSpan()
{
	long 	lowest(INT8_MAX);
	long	span;

	if (v.size() <= 1)
		throw NoSpanException();
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		for (std::vector<int>::const_iterator jt = it + 1; jt != v.end(); jt++)
		{
			if (*it > *jt)
				span = static_cast<long>(*it) - static_cast<long>(*jt);
			else
				span = static_cast<long>(*jt) - static_cast<long>(*it);
			if (!span)
				return (0);
			if (lowest > span)
				lowest = span;
		}
	}
	return (lowest);
}

unsigned int	Span::getSize() const
{
	return (this->size);
}
