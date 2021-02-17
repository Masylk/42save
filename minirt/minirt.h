/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:15:20 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/17 17:06:31 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "lib/libft.h"

typedef struct	s_tlist
{
	char			*tag;
	void			*content;
	struct s_list	*next;
}				t_tlist;

typedef	struct	s_vector
{
	double			x;
	double			y;
	double			z;
	double			(*length)(struct s_vector a);
	struct s_vector	(*normal)(struct s_vector a);
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

typedef struct	s_alight
{
	t_vector		colour;
	unsigned int	ratio;
}				t_alight;

typedef struct	s_light
{

	t_vector		colour;
	t_vector		coor;
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
	t_tlist			cameras;
	t_tlist			spheres;
	t_tlist			squares;
	t_tlist			triangles;
	t_tlist			cylindres;
	t_tlist			planes;
}				t_data;

int				ft_tablen(char **tab);
int				get_double(double *n, char *str);
int				get_point(char *str, int *a, int *b, int *c);
int				str_digit(char *str);
void			freetab(char **tab);
int				get_flag(char *str);
int				parse_sphere(t_data *data, char *line);
int				parse_square(t_data *data, char *line);
int				parse_cylindre(t_data *data, char *line);
int				parse_plane(t_data *data, char *line);
int				parse_triangle(t_data *data, char *line);
int				parse_camera(t_data *data, char *line);
int				parse_light(t_data *data, char *line);
int				parse_res(t_data *data, char *line);
int				parse_alight(t_data *data, char *line);

#endif
