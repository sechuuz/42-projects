/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:49 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/11 18:21:33 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	pf_handle_address(t_format data, void *c)
{
	unsigned long	n;
	int				len;
	char			hex[17];
	char			buf[32];	

	if (!c)
	{
		write(1, "0x0", 3);
		return (3);
	}
	n = (unsigned long)c;
	ft_strlcpy(hex, "0123456789abcdef", 17);
	len = bufuhextoa(buf, n, hex);
	return (pf_format_num(data, buf, data.prefix, len));
}
