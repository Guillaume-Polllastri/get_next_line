/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:24:01 by gpollast          #+#    #+#             */
/*   Updated: 2025/05/07 20:13:18 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*read_buffer(char **buffer)
{
	char	*stock;
	char	*res;
	int		len;

	if (!*buffer || !ft_strchr(*buffer, '\n'))
		return (NULL);
	len = ft_strchr(*buffer, '\n') - *buffer;
	res = ft_substr(*buffer, 0, len + 1);
	stock = *buffer;
	*buffer = ft_substr(*buffer, len + 1, ft_strlen(*buffer) - (len + 1));
	free(stock);
	return (res);
}

ssize_t	write_buffer(int fd, char **buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*stock;
	ssize_t	status;

	ft_bzero(tmp, BUFFER_SIZE + 1);
	status = read(fd, tmp, BUFFER_SIZE);
	if (!*buffer && status > 0)
		*buffer = ft_strdup(tmp);
	else if (status > 0)
	{
		stock = *buffer;
		*buffer = ft_strjoin(*buffer, tmp);
		free(stock);
	}
	return (status);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		status;
	char		*tmp;

	status = 1;
	while (status > 0)
	{
		line = read_buffer(&buffer);
		if (line)
			return (line);
		status = write_buffer(fd, &buffer);
		if (status < 0)
			return (NULL);
		if (status == 0)
		{
			tmp = buffer;
			buffer = NULL;
			return (tmp);
		}
	}
	return (NULL);
}