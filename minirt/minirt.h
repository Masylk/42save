/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:15:20 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/03 15:20:10 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "lib/libft.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mlxdata
{
	void		*mlx;
	void		*win;
}				t_mlxdata;

typedef	struct	s_vector
{
	double			x;
	double			y;
	double			z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

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
	t_vector	colour;
	double		ratio;
}				t_alight;

typedef struct	s_light
{

	t_vector		colour;
	t_vector		coor;
	double			ratio;
	struct s_light	*next;
}				t_light;

typedef struct	s_camera
{
	t_vector		coor;
	t_vector		v;
	double			fov;
	struct s_camera	*next;
}				t_camera;

typedef struct	s_sphere
{
	t_vector		coor;
	t_vector		colour;
	double			width;
	struct s_sphere	*next;
}				t_sphere;

typedef struct	s_plane
{
	t_vector		coor;
	t_vector		v;
	t_vector		colour;
	struct s_plane	*next;
}				t_plane;

typedef struct	s_square
{
	t_vector		coor;
	t_vector		v;
	t_vector		colour;
	double			width;
	struct s_square	*next;
}				t_square;

typedef struct	s_cyl
{
	t_vector		coor;
	t_vector		v;
	t_vector		colour;
	double			width;
	double			height;
	struct s_cyl	*next;
}				t_cyl;

typedef struct	s_triangle
{
	t_vector			coor_a;
	t_vector			coor_b;
	t_vector			coor_c;
	t_vector			colour;
	struct s_triangle	*next;
}				t_triangle;

typedef struct	s_elem
{
	double		pos;
	t_vector	colour;
	t_vector	normale;
	t_vector	point;
}				t_elem;

typedef struct	s_tools
{
	double		a;
	double		b;
	double		c;
	t_vector	d;
	double		t;
	double		t_one;
	double		t_two;
	t_vector	v;
	t_vector	dist;
}		t_tools;

typedef struct	s_data
{
	t_mlxdata		mlxdata;
	t_img			curr_image;
	t_resolution	resolution;
	t_alight		alight;
	t_light			*lights;
	t_camera		*cameras;
	t_sphere		*spheres;
	t_square		*squares;
	t_triangle		*triangles;
	t_cyl			*cylindres;
	t_plane			*planes;
	t_elem			elem;
}				t_data;

int				ft_tablen(char **tab);
int				get_double(double *n, char *str);
int				get_point(char *str, t_vector *v);
int				str_digit(char *str);
int				freetab(char **tab, int value);
int				get_flag(char *str);
int				set_parsers(int (***f)(t_data *d, char *s));
int				parse_sphere(t_data *data, char *line);
int				parse_square(t_data *data, char *line);
int				parse_cylindre(t_data *data, char *line);
int				parse_plane(t_data *data, char *line);
int				parse_triangle(t_data *data, char *line);
int				parse_camera(t_data *data, char *line);
int				parse_light(t_data *data, char *line);
int				parse_res(t_data *data, char *line);
int				parse_alight(t_data *data, char *line);
int				setdata_lists(t_data *data);
void			printsphere(t_sphere sphere);
void			printsquare(t_square square);
void			printplane(t_plane plane);
void			printcyl(t_cyl cyl);
void			printtriangle(t_triangle triangle);
void			printlight(t_light light);
void			printalight(t_alight alight);
void			printres(t_resolution res);
void			printcamera(t_camera camera);
void			printlights(t_light *list);
void			printspheres(t_sphere *list);
void			printsquares(t_square *list);
void			printplanes(t_plane *list);
void			printcylindres(t_cyl *list);
void			printtriangles(t_triangle *list);
void			printlights(t_light *list);
void			printcameras(t_camera *list);
void			print_data(t_data *data);
int				destroydata(t_data *data);
int				clear_mlxdata(t_mlxdata *mlxdata);
int				init_window(t_data *data);
int				set_hooks(t_data *data);
int				keypress(int keycode, t_data *data);
int				keyrelease(int keycode, t_data *data);
int				quit_process(t_data *data);
double			min_d(double a, double b);
double			max_d(double a, double b);
double			dot_product(t_vector i, t_vector j);
double			get_length(t_vector v);
t_vector		normalize(t_vector v);
void			my_mlx_pixel_put(t_data *data, int x, int y);
t_vector		mat_to_vector(int **m, t_vector src);
t_vector		cross_product(t_vector i, t_vector j);
t_vector		add(t_vector a, t_vector b);
t_vector		sub(t_vector a, t_vector b);
t_vector		mul(t_vector a, t_vector b);
t_vector		mul_n(t_vector v, double n);
double			check_sphere(t_sphere *sphere, t_ray ray);
int				check_spheres(t_data *data, t_ray ray);
int				check_squares(t_data *data, t_ray ray);
int				check_triangles(t_data *data, t_ray ray);
int				check_planes(t_data *data, t_ray ray);
int				check_cylinders(t_data *data, t_ray ray);
double			check_caps(t_ray ray, t_cyl *cyl);
double			check_circle(t_ray ray, t_cyl *cyl);
#endif
