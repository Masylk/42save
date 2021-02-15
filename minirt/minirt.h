#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>

typedef	struct	s_vector
{
	float	            x;
	float	            y;
	float	            z;
	float               (*length)(struct s_vector a);
    struct s_vector     (*normal)(struct s_vector a);
}				t_vector;

typedef struct	s_matrices
{
	int	col;
	int	row;
	int	**mat;
}				t_matrices;

#endif
