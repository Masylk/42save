#include "minirt.h"

double	min_d(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double	max_d(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}
