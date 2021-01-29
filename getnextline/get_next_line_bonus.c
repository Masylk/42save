/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:50:39 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/29 15:28:37 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	if (!buffer)
		return (-1);
	chr = ft_strchr(buffer, '\n');
	line_length = ft_strlen(buffer) - ft_strlen(chr);
	ft_concat(line, buffer, line_length);
	if (!chr)
		result = -1;
	else
		result = line_length;
	return (result);
}

int		get_prev(char **previous_buffer, char *buffer, int index)
{
	char	*tmp;

	tmp = ft_strdup(buffer);
	free(*previous_buffer);
	*previous_buffer = ft_strdup(tmp + index + 1);
	if (!(*previous_buffer))
		return (-1);
	free(tmp);
	return (1);
}

int		read_line(int fd, char **line, char **previous_buffer)
{
	int		index;
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	index = -1;
	while (index < 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			return (0);
		if (ret < 0)
		{
			free(*line);
			*line = NULL;
			return (-1);
		}
		buffer[ret] = '\0';
		index = get_line(line, buffer);
	}
	ret = get_prev(previous_buffer, buffer, index);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			index;
	int			ret;
	static char	*previous_buffer[1500];

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	*line = malloc(sizeof(char) * 1);
	if (!(*line))
		return (-1);
	*line[0] = '\0';
	index = get_line(line, previous_buffer[fd]);
	if (index < 0)
	{
		ret = read_line(fd, line, &previous_buffer[fd]);
		if (ret == 0)
			return (0);
		else if (ret < 0)
			return (-1);
	}
	else
		ret = get_prev(&previous_buffer[fd], previous_buffer[fd], index);
	return (1);
}
