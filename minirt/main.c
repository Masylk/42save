/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:25:58 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/03 14:04:35 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	print_data(&data);
	if (init_window(&data) < 0)
		return (destroydata(&data));	
	my_mlx_pixel_put(&data, data.resolution.width, data.resolution.height);
	mlx_put_image_to_window(data.mlxdata.mlx, data.mlxdata.win, data.curr_image.img, 0, 0);
	set_hooks(&data);
	mlx_loop(data.mlxdata.mlx);
}
