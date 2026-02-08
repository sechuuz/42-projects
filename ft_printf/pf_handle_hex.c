/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:28:47 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/11 17:09:51 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_handle_hex(t_format data, unsigned int n)
{
	int			len;
	char		hex[17];
	char		buf[32];	

	if (data.type == 'x')
		ft_strlcpy(hex, "0123456789abcdef", 17);
	else
		ft_strlcpy(hex, "0123456789ABCDEF", 17);
	len = bufuhextoa(buf, (unsigned long long)n, hex);
	if (n == 0)
		data.prefix = 0;
	return (pf_format_num(data, buf, data.prefix, len));
}
