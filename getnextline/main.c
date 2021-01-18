/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:00:34 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/18 15:19:26 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		result;

	result = 1; 
	line = NULL;
	if (ac <= 0)
		return 0;
	fd = open(av[1], O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (result != -1)
		{
			printf("%s\n", line);
			//ft_putstr_fd(line, 1);
//			if (result)
//				ft_putchar_fd('\n', 1);
		}
		free(line);
	}

}
