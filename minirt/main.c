/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:25:58 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/21 12:39:48 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

/*int				keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	printf("%d\n", keycode);
	return (0);
}*/

int	parse_file(char *str, t_data *data)
{
	int		fd;
	int		ret;
	char	*line;
	int		(**parsers)(t_data *d, char *s);

	ret = 1;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (!(set_parsers(&parsers)))
		return (-1);
	print_data(data);
	while(get_next_line(fd, &line) > 0 && ret >= 0)
	{
		ret = get_flag(line);
		if (ret >= 0)
		{
			if (!(*parsers[ret])(data, line))
				return (0);
		}
		free(line);
	}
	free(line);
	close(fd);
	return (ret);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac < 2)
		return (0);
	setdata_lists(&data);
	if (parse_file(av[1], &data) < 0)
		return (0);
	if (init_window(&data) < 0)
		return (destroydata(&data));
	/*
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FFFF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	vars.win = mlx_win;
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 3, 1L << 1, keyrelease, &vars);
	mlx_loop(mlx);*/
}
