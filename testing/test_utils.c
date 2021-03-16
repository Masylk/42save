/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:21:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/19 15:17:24 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	printsphere(t_sphere sphere)
{
	printf("coor : x %f y %f z %f\n", sphere.coor.x, sphere.coor.y, sphere.coor.z);
	printf("width : %f\n", sphere.width);
	printf("colour : R %f G %f B %f\n", sphere.colour.x, sphere.colour.y, sphere.colour.z);
}

void	printsquare(t_square square)
{
	printf("coor : x %f y %f z %f\n", square.coor.x, square.coor.y, square.coor.z);
	printf("orientation : x %f y %f z %f\n", square.v.x, square.v.y, square.v.z);
	printf("width : %f\n", square.width);
	printf("colour : R %f G %f B %f\n", square.colour.x, square.colour.y, square.colour.z);
}

void	printplane(t_plane plane)
{
	printf("coor : x %f y %f z %f\n", plane.coor.x, plane.coor.y, plane.coor.z);
	printf("orientation : x %f y %f z %f\n", plane.v.x, plane.v.y, plane.v.z);
	printf("colour : R %f G %f B %f\n", plane.colour.x, plane.colour.y, plane.colour.z);
}

void	printcyl(t_cyl cyl)
{
	printf("coor : x %f y %f z %f\n", cyl.coor.x, cyl.coor.y, cyl.coor.z);
	printf("orientation : x %f y %f z %f\n", cyl.v.x, cyl.v.y, cyl.v.z);
	printf("width : %f\n", cyl.width);
	printf("height : %f\n", cyl.height);
	printf("colour : R %f G %f B %f\n", cyl.colour.x, cyl.colour.y, cyl.colour.z);
}

void	printtriangle(t_triangle triangle)
{
	printf("coor a : x %f y %f z %f\n", triangle.coor_a.x, triangle.coor_a.y, triangle.coor_a.z);
	printf("coor B : x %f y %f z %f\n", triangle.coor_b.x, triangle.coor_b.y, triangle.coor_b.z);
	printf("coor c : x %f y %f z %f\n", triangle.coor_c.x, triangle.coor_c.y, triangle.coor_c.z);
	printf("colour : R %f G %f B %f\n", triangle.colour.x, triangle.colour.y, triangle.colour.z);
}

void	printlight(t_light light)
{
	printf("coor : x %f y %f z %f\n", light.coor.x, light.coor.y, light.coor.z);
	printf("ratio : %f\n", light.ratio);
	printf("colour : R %f G %f B %f\n", light.colour.x, light.colour.y, light.colour.z);
}

void	printalight(t_alight alight)
{
	printf("    alight\n");
	printf("ratio : %f\n", alight.ratio);
	printf("colour : R %f G %f B %f\n", alight.colour.x, alight.colour.y, alight.colour.z);
}

void	printres(t_resolution res)
{
	printf("    Resolution\n");
	printf("width : %u\n", res.width);
	printf("height : %u\n", res.height);
}

void	printcamera(t_camera camera)
{
	printf("coor : x %f y %f z %f\n", camera.coor.x, camera.coor.y, camera.coor.z);
	printf("orientation : x %f y %f z %f\n", camera.v.x, camera.v.y, camera.v.z);
	printf("field of view : %f\n", camera.fov);
}
