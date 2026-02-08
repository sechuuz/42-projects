/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:39:42 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 18:11:16 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	if (!dst && !src)
		return (dst);
	if (len == 0)
		return (dst);
	a = dst;
	b = src;
	i = 0;
	if (a > b && a < b + len)
	{
		while (len-- > 0)
			a[len] = b[len];
	}
	else
	{
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}
