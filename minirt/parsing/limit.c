#include "minirt.h"

int	lim(double n, double min, double max)
{
	if (n > max || n < min)
		return (1);
	return (0);
}

int	limvec(t_vector v, double min, double max)
{
	if (v.x > max || v.x < min)
		return (1);
	if (v.y > max || v.y < min)
		return (1);
	if (v.z > max || v.z < min)
		return (1);
	return (0);
}

int	limcyl(t_cyl *cyl)
{
	if (cyl->width <= 0)
		return (0);
	if (cyl->height <= 0)
		return (0);
	if (limvec(cyl->v, -1, 1))
		return (0);
	cyl->v = normalize(cyl->v);
	if (limvec(cyl->colour, 0, 255))
		return (0);
	return (1);
}
