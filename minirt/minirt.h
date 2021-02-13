#ifndef MINIRT_H
# define MINIRT_H

typedef	struct	s_vector
{
	float	x;
	float	y;
	float	z;
	float	(*length)(struct s_vector a);
}				t_vector;

#endif
