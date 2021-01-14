/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:50:39 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/14 18:58:23 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_concat(char **dest, char *src, int srclen)
{
	char	*tmp;

	tmp = *dest;
	*dest = malloc(sizeof(char) * (ft_strlen(tmp) + srclen + 1));
	if (!dest)
	{
		free(tmp);
		return (NULL);
	}
	if (tmp)
		ft_strlcpy(*dest, tmp, ft_strlen(tmp) + 1);
	ft_strlcat(*dest, src, ft_strlen(*dest) + srclen + 1);
//	free(tmp);
	return (*dest);
}

int		get_line(char **line, char *buffer)
{
	int		line_length;
	char	*chr;
	int		result;

	chr = ft_strchr(buffer, '\n');
	line_length = ft_strlen(buffer) - ft_strlen(chr);
	ft_concat(line, buffer, line_length);
	if (!chr)
		result = -1;
	else
		result = line_length;
	return (result);
}

int		get_next_line(int fd, char **line)
{
    int			index;
    int			ret;
    char		buffer[BUFFER_SIZE];
    static char	*previous_buffer;

	if (*line)
		free(*line);
	if (previous_buffer)
	{
		if (previous_buffer[0] != '\n' && !(ft_concat(line, previous_buffer, ft_strlen(previous_buffer))))
			return (-1);
		free(previous_buffer);
	}
	index = -1;
	while (index < 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			return (0);
		if (ret < 0)
			return (-1);
		index = get_line(line, buffer);  
	}
    // lorsque la ligne est complète, mettre le reste du buffer dans l'array static
	if(!(ft_concat(&previous_buffer, buffer + (index + 1), ft_strlen(buffer + index + 1))))
		return (-1);
	printf("prev : %s\n", previous_buffer);
	return (1);
}
