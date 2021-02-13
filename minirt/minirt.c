#include "minirt.h"
#include <stdio.h>

float   get_length(t_vector v)
{
	float	a;
	float	b;
	float	c;
	
	a = v.x * v.x;
	b = v.y * v.y;
	c = v.z * v.z;
	return(a + b + c);
}


int	main()
{
	t_vector a;

	a.x = 1;
	a.y = 2;
	a.z = 3;
	a.length = &get_length;
	printf("len : %f", a.length(a));
}
