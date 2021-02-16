#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "lib/libft.h"

typedef struct	s_list
{
	char			*tag;
	void			*content;
	struct s_list	*next;
}				t_list;

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

typedef struct	s_resolution
{
	unsigned int	width;
	unsigned int	height;
}				t_resolution;

typedef struct	s_light
{
	t_vector		colour;
	unsigned int	ratio;
}				t_light;

typedef struct	s_camera
{
	t_vector	coor;
	t_vector	v;
	double		width;
}				t_camera;

typedef struct	s_sphere
{
	t_vector	coor;
	t_vector	colour;
	double		width;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	coor;
	t_vector	v;
	t_vector	colour;
}				t_plane;

typedef struct	s_square
{
	t_vector	coor;
	t_vector	v;
	t_vector	colour;
	double		width;
}				t_square;

typedef struct	s_cyl
{
	t_vector	coor;
	t_vector	v;
	t_vector	colour;
	double		width;
	double		height;
}				t_cyl;

typedef struct	s_triangle
{
	t_vector	coor_a;
	t_vector	coor_b;
	t_vector	coor_c;
	t_vector	colour;
}				t_triangle;

typedef struct	s_data
{
	t_resolution	resolution;
	t_light			light;
	t_list			cameras;
	t_list			spheres;
	t_list			squares;
	t_list			triangles;
	t_list			cylindres;
	t_list			planes;
}				t_data;

int		ft_tablen(char **tab);
int		get_double(double *n, char *str);
int		get_point(char *str, int *a, int *b, int *c);
int		str_digit(char *str);
void    freetab(char **tab);

#endif
