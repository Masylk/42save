#include "minirt.h"

t_vector	cross_product(t_vector i, t_vector j)
{
	t_vector	result;

	result.x = i.y * j.z - i.z * j.y;
	result.y = i.z * j.x - i.x * j.z;
	result.z = i.x * j.y - i.y * j.x;
	return (result);
}

t_vector	add(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vector	sub(t_vector a, t_vector b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vector	mul(t_vector a, t_vector b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vector	mul_n(t_vector v, double n)
{
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}
