#include "minirt.h"

double	check_caps(double t_one, t_ray ray, t_cyl *cyl)
{
	t_vector	q;
	double		denom;
	double		t;
	t_vector	top;
	t_vector	bottom;

	top = add(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	bottom = sub(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	denom = dot_product(ray.direction, cyl->v);
	if (denom == 0)
		return (t_one);
	t = dot_product(sub(ray.origin, bottom), cyl->v) / denom;
	q = sub(add(ray.origin, mul_n(ray.direction, t)), bottom);
	if (t <= 0 || dot_product(q, q)
			>= ((cyl->width * 0.5) * (cyl->width * 0.5)))
		t = t_one;
	t_one = dot_product(sub(ray.origin, top), cyl->v) / denom;
	q = sub(add(ray.origin, mul_n(ray.direction, t_one)), top);
	if (t_one > 0 && dot_product(q, q)
			< ((cyl->width * 0.5) * (cyl->width * 0.5)))
		if (t > t_one && t_one > 0)
			t = t_one;
	return (t);
}

double	is_inplanes(double t_one, double t_two, t_ray ray, t_cyl *cyl)
{
	t_vector	q;
	t_vector	p_one;
	t_vector	p_two;
	double		t;

	t = -1;
	p_one = sub(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	p_two = add(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	if (t_one > 0)
	{
		q = add(ray.origin, mul_n(ray.direction, t_one));
		if (dot_product(cyl->v, sub(q, p_one)) > 0
				&& dot_product(cyl->v, sub(q, p_two)) < 0)
			t = t_one;
	}
	if (t_two > 0)
	{
		q = add(ray.origin, mul_n(ray.direction, t_two));
		if (dot_product(cyl->v, sub(q, p_one)) <= 0
				|| dot_product(cyl->v, sub(q, p_two)) >= 0)
			return (t);
		if (t > t_two || t < 0)
			t = t_two;
	}
	return (t);
}

double  check_tops(t_ray ray, t_cyl *cyl)
{
	double          a;
	double          b;
	double          c;
	t_vector        dist;
	double          area;

	a = dot_product(sub(ray.origin, cyl->coor), cyl->v);
	b = dot_product(ray.direction, cyl->v);
	if (b == 0 || (a > 0 && b > 0) || (a < 0 && b < 0))
		return (0);
	c = -(a / b);
	area = (cyl->width * 0.5 * cyl->width * 0.5) * (M_PI / 180);
	dist = sub(add(mul_n(ray.direction, c), ray.origin), cyl->coor);
	if (fabs(dist.x) > area || fabs(dist.y) > area)
		return (0);
	if (c > 0)
		return (1);
	return (0);
}

double	check_circle(t_ray ray, t_cyl *cyl)
{
	t_vector	point;
	double		a;
	double		b;
	double		c;

	a = dot_product(sub(ray.origin, cyl->coor), cyl->v);
	b = dot_product(ray.direction, cyl->v);
	if (b == 0 || (a > 0 && b > 0) || (a < 0 && b < 0))
		return (0);
	c = -(a / b);
	point = sub(add(ray.origin, mul_n(ray.direction, c)), cyl->coor);
	if (dot_product(point, point) > cyl->width * 0.5 * cyl->width * 0.5)
		return (-1);
	else
		return (c);
}

double	check_disc(double d, t_ray ray, t_cyl *cyl, double a, double b)
{
	double		sq;
	double		t_one;
	double		t_two;
	double		t;

	sq = sqrt(d);
	a = 2.0 * a;
	t_one = (-b + sq) / a;
	t_two = (-b - sq) / a;
	if (t_one <= 0 && t_two <= 0)
		return (-1);
	t_one = is_inplanes(t_one, t_two, ray, cyl);
	if (t_one < 0)
		return (-1);
	return (t_one);
	t = check_tops(ray, cyl);
	if ((t > t_one && t_one > 0) || (t <= 0))
		t = t_one;
	return (t);
	//return (check_caps(t_one, ray, cyl));
}
//faire une structure t_tools pour les variables des équations
// a,b,c,d
// t,q,p, t_one, t_two
// v, r

int	check_cylinder(t_cyl *cyl, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_vector	d;
	t_vector	v;
	double		res;

	v = sub(ray.direction,
			mul_n(cyl->v, dot_product(ray.direction, cyl->v)));
	d = sub(ray.origin, cyl->coor);
	a = dot_product(v, v);
	b = 2.0 * dot_product(v,
			sub(d, mul_n(cyl->v, dot_product(d, cyl->v))));
	v = sub(d, mul_n(cyl->v, dot_product(d, cyl->v)));
	c = dot_product(v, v) - ((cyl->width * 0.5) * (cyl->width * 0.5));
	c = (b * b) - (4 * a * c);
	res = -1;
	if (c >= 0)
		res = check_disc(c, ray, cyl, a, b);
	if (res <= 0)
		res = check_circle(ray, cyl);
	if (res <= 0)
		return (0);
	return (1);
}

int	check_cylinders(t_data *data, t_ray ray)
{
	t_cyl	*tmp;

	tmp = data->cylindres;
	while(tmp)
	{
		if (check_cylinder(tmp, ray))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

