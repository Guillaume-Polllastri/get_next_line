/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guill <guill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:39:26 by gpollast          #+#    #+#             */
/*   Updated: 2025/05/09 13:52:24 by guill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;

	if (len >= (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	ns = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ns)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ns);
	ft_strlcpy(ns, s + start, len + 1);
	return (ns);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len_total;
	int		i;
	int		j;

	len_total = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * (len_total + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*nstr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	nstr = (char *) malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		nstr[i] = s[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}