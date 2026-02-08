/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:59:54 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/11 14:03:38 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*b;
	unsigned char		nc;
	size_t				i;

	b = s;
	nc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (b[i] == nc)
			return ((void *)&b[i]);
		i++;
	}
	return (0);
}
