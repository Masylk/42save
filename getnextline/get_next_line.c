/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:50:39 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/15 18:55:29 by mtogbe           ###   ########.fr       */
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
	*dest[0] = '\0';
	if (tmp)
		ft_strlcpy(*dest, tmp, ft_strlen(tmp) + 1);
	ft_strlcat(*dest, src, ft_strlen(*dest) + srclen + 1);
	free(tmp);
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
    char		buffer[BUFFER_SIZE + 1];
    static char	*previous_buffer = NULL;

	if (previous_buffer)
	{
		//en faire une fonction
		if (!(ft_concat(line, previous_buffer, ft_strlen(previous_buffer))))
			return (-1);
		free(previous_buffer);
		previous_buffer = NULL;
	}
	index = -1;
	while (index < 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		//renvoyer une line vide
		if (ret == 0)
		{
			*line = malloc(sizeof(char) * 1);
			*line[0] = '\0';
			return (0);
		}
		if (ret < 0)
			return (-1);
		buffer[BUFFER_SIZE] = '\0';
		index = get_line(line, buffer);  
	}
	if(!(ft_concat(&previous_buffer, buffer + (index + 1), ft_strlen(buffer + (index + 1)))))
		return (-1);
	return (1);
}
