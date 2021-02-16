#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>


typedef struct	s_resolution
{
	unsigned int	width;
	unsigned int	height;
}				t_resolution;

typedef struct	s_light
{
	t_colour		colour;
	unsigned int	ratio;
}				t_light;

typedef	struct	s_vector
{
	double	            x;
	double	            y;
	double	            z;
	double              (*length)(struct s_vector a);
    struct s_vector     (*normal)(struct s_vector a);
}				t_vector;

typedef struct	s_matrices
{
	int	col;
	int	row;
	int	**mat;
}				t_matrices;

typedef struct	s_colour
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}				t_colour;

typedef struct	s_sphere
{
	t_vector	coor;
	t_colour		colour;
	double		width;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	coor;
	t_vector	v;
	t_colour	colour;
}				t_plane;

typedef struct	s_square
{
	t_vector	coor;
	t_vector	v;
	t_colour	colour;
	double		width;
}				t_square;

typedef struct	s_cyl
{
	t_vector	coor;
	t_vector	v;
	t_colour	colour;
	double		width;
	double		height;
}				t_cyl;

typedef struct	s_triangle
{
	t_vector	coor_a;
	t_vector	coor_b;
	t_vector	coor_c;
	t_colour	colour;
}				t_triangle;

#endif
