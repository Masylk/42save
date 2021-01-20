/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:50:39 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/18 15:44:28 by mtogbe           ###   ########.fr       */
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
	char		*curr;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	*line = malloc(sizeof(char) * 1);
	*line[0] = '\0';
	curr = ft_strdup(previous_buffer);
	index = -1;
	if (curr)
		index = get_line(line, curr);
	while (index < 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			return (0);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		curr = buffer;
		index = get_line(line, curr);
	}
	free(previous_buffer);
	previous_buffer = ft_strdup(curr + index + 1);
	if (curr != buffer)
		free(curr);
	if (!previous_buffer)
		return (-1);
	return (1);
}
