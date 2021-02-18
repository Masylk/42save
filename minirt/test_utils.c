/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:21:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/18 16:30:43 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	printsphere(t_sphere sphere)
{
	printf("coor : x %e y %e z %e\n", sphere.coor.x, sphere.coor.y, sphere.coor.z);
	printf("colour : r %e g %e b %e\n", sphere.colour.x, sphere.colour.y, sphere.colour.z);
	printf("width : %e\n", sphere.width);
}

void	printsquare(t_square square)
{
	printf("coor : x %e y %e z %e\n", square.coor.x, square.coor.y, square.coor.z);
	printf("orientation : x %e y %e z %e\n", square.v.x, square.v.y, square.v.z);
	printf("colour : r %e g %e b %e\n", square.colour.x, square.colour.y, square.colour.z);
	printf("width : %e\n", square.width);
}

void	printplane(t_plane plane)
{
	printf("coor : x %e y %e z %e\n", plane.coor.x, plane.coor.y, plane.coor.z);
	printf("colour : r %e g %e b %e\n", plane.colour.x, plane.colour.y, plane.colour.z);
}

void	printcyl(t_cyl cyl)
{
	printf("coor : x %e y %e z %e\n", cyl.coor.x, cyl.coor.y, cyl.coor.z);
	printf("colour : r %e g %e b %e\n", cyl.colour.x, cyl.colour.y, cyl.colour.z);
	printf("width : %e\n", cyl.width);
}

void	printtriangle(t_triangle triangle)
{
	printf("coor a : x %e y %e z %e\n", triangle.coor_a.x, triangle.coor_a.y, triangle.coor_a.z);
	printf("colour : r %e g %e b %e\n", triangle.colour.x, triangle.colour.y, triangle.colour.z);
}

void	printlight(t_light light)
{
	printf("coor : x %e y %e z %e\n", light.coor.x, light.coor.y, light.coor.z);
	printf("colour : r %e g %e b %e\n", light.colour.x, light.colour.y, light.colour.z);
}

void	printalight(t_alight alight)
{
	printf("colour : r %e g %e b %e\n", alight.colour.x, alight.colour.y, alight.colour.z);
}

void	printres(t_resolution res)
{
	printf("width : %u\n", res.width);
	printf("height : %u\n", res.height);
}

void	printcamera(t_camera camera)
{
	printf("coor : x %e y %e z %e\n", camera.coor.x, camera.coor.y, camera.coor.z);
}
