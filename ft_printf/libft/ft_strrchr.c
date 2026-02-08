/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:24:15 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 18:04:02 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*l;
	unsigned char	nc;

	nc = (unsigned char)c;
	l = 0;
	while (*s != '\0')
	{
		if (*s == nc)
		{
			l = ((char *)s);
		}
		s++;
	}
	if (nc == '\0')
		return ((char *)s);
	return ((char *)l);
}
