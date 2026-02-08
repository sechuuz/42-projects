/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bufitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:44:07 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/11 17:11:52 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bufitoa(char *buf, long long num)
{
	int		digits;
	int		i;
	char	tmp;

	digits = 0;
	i = 0;
	if (num == 0)
		return (ft_strlcpy(buf, "0", 2));
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		buf[digits++] = (num % 10) + '0';
		num /= 10;
	}
	while (i < digits / 2)
	{
		tmp = buf[i];
		buf[i] = buf[digits - 1 - i];
		buf[digits - 1 - i] = tmp;
		i++;
	}
	return (digits);
}
