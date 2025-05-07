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

int	*get_line(char *buffer)
{
	if (ft_strchr(buffer, '\n') == NULL)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	void	*buffer;
	char	*tmp;

	if (read(fd, buffer[], BUFFER_SIZE) == 0 || get_line(buffer) == 1)
		return (le resultat);
}
