/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:28:55 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/20 12:30:56 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_matoi(int i, int s, long long n, const char *str)
{
	int			digi;
	long long	appr_max;

	appr_max = 922337203685477580;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digi = str[i] - '0';
		if ((s == 1) && ((n > appr_max) || (digi > 7 && n == appr_max)))
			return (-1);
		else if ((s == -1) && ((n > appr_max) || (digi > 8 && n == appr_max)))
			return (0);
		n = n * 10 + digi;
		i++;
	}
	return (n * s);
}

int	ft_atoi(const char *str)
{
	if (!str)
		return (0);
	return (ft_matoi(0, 1, 0, str));
}
