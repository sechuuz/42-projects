/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:06:11 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 17:57:48 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*bt;
	size_t				i;

	bt = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bt[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
