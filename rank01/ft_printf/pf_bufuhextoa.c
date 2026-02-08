/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bufuhextoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:35:26 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/11 15:10:03 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bufuhextoa(char *buf, unsigned long long num, const char *hex)
{
	int		digits;
	int		i;
	char	tmp;

	digits = 0;
	i = 0;
	if (num == 0)
		return (ft_strlcpy(buf, "0", 2));
	while (num > 0)
	{
		buf[digits++] = hex[num % 16];
		num /= 16;
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
