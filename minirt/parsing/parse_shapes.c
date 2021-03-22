/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:28:34 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/22 18:08:08 by mtogbe           ###   ########.fr       */
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
	sphere->next = data->spheres;
	data->spheres = sphere;
	if (ft_tablen(tab) != 4)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(sphere->coor))))
		return (freetab(tab, 0));
	if (!(get_double(&(sphere->width), tab[2])))
		return (freetab(tab, 0));
	if (!(get_point(tab[3], &(sphere->colour))))
		return (freetab(tab, 0));
	if (limvec(sphere->colour, 0, 255) || sphere->width <= 0)
		return (freetab(tab, 0));
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
	square->next = data->squares;
	data->squares = square;
	if (ft_tablen(tab) != 5)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(square->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(square->v))))
		return (freetab(tab, 0));
	if (!(get_double(&(square->width), tab[3])))
		return (freetab(tab, 0));
	if (!(get_point(tab[4], &(square->colour))))
		return (freetab(tab, 0));
	if (limvec(square->v, -1, 1) || square->width <= 0 ||
			limvec(square->colour, 0, 255))
		return (freetab(tab, 0));
	//square->v = normalize(square->v);
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
	plane->next = data->planes;
	data->planes = plane;
	if (ft_tablen(tab) != 4)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(plane->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(plane->v))))
		return (freetab(tab, 0));
	if (!(get_point(tab[3], &(plane->colour))))
		return (freetab(tab, 0));
	if (limvec(plane->v, -1, 1) || limvec(plane->colour, 0, 255))
		return (freetab(tab, 0));
	plane->v = normalize(plane->v);
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
	cyl->next = data->cylindres;
	data->cylindres = cyl;
	if (ft_tablen(tab) != 6)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(cyl->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(cyl->v))))
		return (freetab(tab, 0));
	if (!(get_double(&(cyl->width), tab[3])))
		return (freetab(tab, 0));
	if (!(get_double(&(cyl->height), tab[4])))
		return (freetab(tab, 0));
	if (!(get_point(tab[5], &(cyl->colour))))
		return (freetab(tab, 0));
	return (freetab(tab, limcyl(cyl)));
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
	triangle->next = data->triangles;
	data->triangles = triangle;
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
	triangle->normale = normalize(cross_product(
			sub(triangle->coor_b, triangle->coor_a),
			sub(triangle->coor_c, triangle->coor_a)));
	return (freetab(tab, 1 - limvec(triangle->colour, 0, 255)));
}
