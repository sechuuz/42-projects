/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:34:00 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/17 14:14:42 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_dup(const char *s1)
{
	int		i;
	char	*c;

	i = 0;
	c = malloc((gnl_len(s1) + 1) * sizeof(char));
	if (!c)
		return (0);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*gnl_join(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1)
		return (gnl_dup(s2));
	if (!s2)
		return (0);
	s3 = malloc((gnl_len(s1) + gnl_len(s2) + 1) * sizeof(char));
	if (!s3)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	free((char *)s1);
	return (s3);
}

size_t	gnl_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_chr(const char *s, int c)
{
	unsigned char	nc;

	if (!s)
		return (0);
	nc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == nc)
		{
			return ((char *)s);
		}
		s++;
	}
	if (nc == '\0')
	{
		return ((char *) s);
	}
	return (0);
}

