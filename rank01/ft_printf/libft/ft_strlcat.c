/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:50:59 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/20 12:42:43 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	cl;
	size_t	dl;
	size_t	sl;

	sl = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (sl);
	dl = ft_strlen(dst);
	if (dl >= dstsize)
	{
		return (dstsize + sl);
	}
	cl = dstsize - dl - 1;
	i = 0;
	while (i < cl && src[i] != '\0')
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}
