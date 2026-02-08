/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:17:48 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/10 18:56:55 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_handle_int(t_format data, int n)
{
	int		len;
	char	sign;
	char	buf[32];

	if (n < 0)
		sign = '-';
	else
		sign = data.prefix;
	len = bufitoa(buf, (long long)n);
	return (pf_format_num(data, buf, sign, len));
}
