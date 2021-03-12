/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:28:34 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/12 15:02:08 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sphere(t_data *data, char *line)
{
	t_sphere	*sphere;
	char		**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!(ft_malloc((void *)&sphere, sizeof(t_sphere), 1)))
		return (freetab(tab, 0));
	if (ft_tablen(tab) != 4)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(sphere->coor))))
		return (freetab(tab, 0));
	if (!(get_double(&(sphere->width), tab[2])))
		return (freetab(tab, 0));
	if (!(get_point(tab[3], &(sphere->colour))))
		return (freetab(tab, 0));
	sphere->next = data->spheres;
	data->spheres = sphere;
	return (freetab(tab, 1));
}

int	parse_square(t_data *data, char *line)
{
	t_square	*square;
	char		**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!(ft_malloc((void *)&square, sizeof(t_square), 1)))
		return (freetab(tab, 0));
	if (ft_tablen(tab) != 5)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(square->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(square->v))))
		return (freetab(tab, 0));
	square->v = normalize(square->v);
	if (!(get_double(&(square->width), tab[3])))
		return (freetab(tab, 0));
	if (!(get_point(tab[4], &(square->colour))))
		return (freetab(tab, 0));
	square->next = data->squares;
	data->squares = square;
	return (freetab(tab, 1));
}

int	parse_plane(t_data *data, char *line)
{
	t_plane	*plane;
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!(ft_malloc((void *)&plane, sizeof(t_plane), 1)))
		return (freetab(tab, 0));
	if (ft_tablen(tab) != 4)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(plane->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(plane->v))))
		return (freetab(tab, 0));
	plane->v = normalize(plane->v);
	if (!(get_point(tab[3], &(plane->colour))))
		return (freetab(tab, 0));
	plane->next = data->planes;
	data->planes = plane;
	return (freetab(tab, 1));
}

int	parse_cylindre(t_data *data, char *line)
{
	t_cyl	*cyl;
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!(ft_malloc((void *)&cyl, sizeof(t_cyl), 1)))
		return (freetab(tab, 0));
	if (ft_tablen(tab) != 6)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(cyl->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(cyl->v))))
		return (freetab(tab, 0));
	cyl->v = normalize(cyl->v);
	if (!(get_double(&(cyl->width), tab[3])))
		return (freetab(tab, 0));
	if (!(get_double(&(cyl->height), tab[4])))
		return (freetab(tab, 0));
	if (!(get_point(tab[5], &(cyl->colour))))
		return (freetab(tab, 0));
	cyl->next = data->cylindres;
	data->cylindres = cyl;
	return (freetab(tab, 1));
}

int	parse_triangle(t_data *data, char *line)
{
	t_triangle	*triangle;
	char		**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!(ft_malloc((void *)&triangle, sizeof(t_triangle), 1)))
		return (freetab(tab, 0));
	if (ft_tablen(tab) != 5)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(triangle->coor_a))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(triangle->coor_b))))
		return (freetab(tab, 0));
	if (!(get_point(tab[3], &(triangle->coor_c))))
		return (freetab(tab, 0));
	if (!(get_point(tab[4], &(triangle->colour))))
		return (freetab(tab, 0));
	triangle->next = data->triangles;
	data->triangles = triangle;
	return (freetab(tab, 1));
}
