/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:25:58 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/17 16:52:27 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_file(char *str, t_data *data)
{
	int		fd;
	int		ret;
	char	*line;
	int		(**parsers)(t_data *d, char *s);

	ret = 1;
	fd = open(str, O_RDONLY);
	if (fd < 0 || !(set_parsers(&parsers)))
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) && ret >= 0)
		{
			ret = get_flag(line);
			if (ret >= 0)
				ret = (*parsers[ret])(data, line) - 1;
		}
		free(line);
	}
	free(parsers);
	free(line);
	return (close(fd) + ret);
}

void	change_planes_next(t_data *data)
{
	t_plane		*plane;
	t_triangle	*triangle;

	plane = data->planes;
	triangle = data->triangles;
	while (plane)
	{
		if (dot_product(plane->v, data->cameras->v) >= 0)
			plane->v = mul_n(plane->v, -1);
		plane = plane->next;
	}
	while (triangle)
	{
		if (dot_product(triangle->normale, data->cameras->v) > 0.1)
			triangle->normale = mul_n(triangle->normale, -1);
		triangle = triangle->next;
	}
}

void	change_planes_normal(t_data *data)
{
	t_square	*square;

	square = data->squares;
	while (square)
	{
		if (dot_product(square->v, data->cameras->v) > 0)
			square->v = mul_n(square->v, -1);
		square = square->next;
	}
	change_planes_next(data);
}

int		create_new_image(t_data *data)
{
	change_planes_normal(data);
	my_mlx_pixel_put(data, data->resolution.width, data->resolution.height);
	mlx_clear_window(data->mlxdata.mlx, data->mlxdata.win);
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->curr_image.img, 0, 0);
	set_hooks(data);
	return (1);
}

int		main(int ac, char **av)
{
	t_data		data;

	if (ac < 2)
	{
		printf("Error\n");
		return (0);
	}
	setdata_lists(&data);
	if (!check_ext(av[1]))
	{
		printf("Error\n");
		return (0);
	}
	if (parse_file(av[1], &data) < 0 || !(data.cameras))
	{
		printf("Error\n");
		return (destroydata(&data));
	}
	if (init_window(&data) < 0)
		return (destroydata(&data));
	create_new_image(&data);
	mlx_loop(data.mlxdata.mlx);
}
