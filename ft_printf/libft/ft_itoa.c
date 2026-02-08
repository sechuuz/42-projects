/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:21:09 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 19:12:20 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_digi(int n)
{
	size_t	digits;

	digits = 0;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*handle_spec(int n)
{
	char	*sn;

	if (n == 0)
	{
		sn = ft_strdup("0");
		return (sn);
	}
	sn = ft_strdup("-2147483648");
	return (sn);
}

char	*ft_itoa(int n)
{
	char		*sn;
	size_t		isn;
	size_t		i;

	isn = 0;
	if (n == -2147483648 || n == 0)
		return (handle_spec(n));
	if (n < 0)
	{
		n = -n;
		isn = 1;
	}
	i = count_digi(n) + isn + 1;
	sn = malloc((i) * sizeof(char));
	if (!sn)
		return (0);
	sn[--i] = '\0';
	while (n > 0)
	{
		sn[--i] = (n % 10) + '0';
		n /= 10;
	}
	if (isn == 1)
		sn[0] = '-';
	return (sn);
}
