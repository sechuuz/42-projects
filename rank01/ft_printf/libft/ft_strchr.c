/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:33:43 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 18:01:40 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	nc;

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
