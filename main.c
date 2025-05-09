/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:13:56 by gpollast          #+#    #+#             */
/*   Updated: 2025/05/08 13:14:10 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
    int fd;
    char    *line;

    fd = open("get_next_line.c", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("a%s", line);
    }
    return (0);
}
