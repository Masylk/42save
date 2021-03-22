/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2121/12/18 16:21:11 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/22 18:05:59 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_data(t_data *data)
{
	printf("----------------DATA----------------\n");
	printres(data->resolution);
	printalight(data->alight);
	printcameras(data->cameras);
	printlights(data->lights);
	printspheres(data->spheres);
	printsquares(data->squares);
	printplanes(data->planes);
	printtriangles(data->triangles);
	printcylindres(data->cylindres);
	printf("----------------DATA----------------\n");
}

void	printlights(t_light *list)
{
	t_light	light;
	int	i;

	i = 1;
	printf("    Lights : \n");
	while (list)
	{
		printf("---%d---\n", i++);
		light.coor = list->coor;
		light.colour = list->colour;
		light.ratio = list->ratio;
		printlight(light);
		list = list->next;
	}
	printf("\n");
}

void	printspheres(t_sphere *list)
{
	t_sphere	sphere;
	int			i;

	i = 1;
	printf("   Spheres : \n");
	while (list)
	{
		printf("---%d---\n", i++);
		sphere.coor = list->coor;
		sphere.colour = list->colour;
		sphere.width = list->width;
		printsphere(sphere);
		list = list->next;
	}
	printf("\n");
}

void	printcameras(t_camera *list)
{
	t_camera	camera;
	int			i;
	t_camera	*tmp;

	i = 1;
	tmp = list;
	printf("    Cameras : \n");
	while (!(list == tmp && i != 1))
	{
		printf("---%d---\n", i++);
		camera.coor = tmp->coor;
		camera.v = tmp->v;
		camera.fov = tmp->fov;
		printcamera(camera);
		tmp = tmp->next;
	}
	printf("\n");
}

void	printplanes(t_plane *list)
{
	t_plane	plane;
	int		i;

	i = 1;
	printf("   Planes : \n");
	while (list)
	{
		printf("---%d---\n", i++);
		plane.coor = list->coor;
		plane.colour = list->colour;
		plane.v = list->v;
		printplane(plane);
		list = list->next;
	}
	printf("\n");
}

void	printsquares(t_square *list)
{
	t_square	square;
	int			i;

	i = 1;
	printf("   Squares : \n");
	while (list)
	{
		printf("---%d---\n", i++);
		square.coor = list->coor;
		square.colour = list->colour;
		square.v = list->v;
		square.width = list->width;
		printsquare(square);
		list = list->next;
	}
	printf("\n");
}

void	printtriangles(t_triangle *list)
{
	t_triangle	triangle;
	int			i;

	i = 1;
	printf("   Triangles : \n");
	while (list)
	{
		printf("---%d---\n", i++);
		triangle.coor_a = list->coor_a;
		triangle.coor_b = list->coor_b;
		triangle.coor_c = list->coor_c;
		triangle.colour = list->colour;
		printtriangle(triangle);
		list = list->next;
	}
	printf("\n");
}

void	printcylindres(t_cyl *list)
{
	t_cyl	cyl;
	int		i;

	i = 1;
	printf("   Cylindres : \n");
	while (list)
	{
		printf("---%d---\n", i++);
		cyl.coor = list->coor;
		cyl.colour = list->colour;
		cyl.v = list->v;
		cyl.width = list->width;
		cyl.height = list->height;
		printcyl(cyl);
		list = list->next;
	}
	printf("\n");
}
