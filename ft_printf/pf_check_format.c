/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:04:32 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/12 16:52:05 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_check_format(t_format data, va_list arg)
{
	int	printed;

	printed = 0;
	if (!data.type)
		return (0);
	if (data.precision >= 0 && data.type != 'c' && data.type != 's'
		&& data.type != '%')
		data.padding = ' ';
	if (data.type == 'c')
		printed += pf_handle_char(data, (char)va_arg(arg, int));
	if (data.type == 's')
		printed += pf_handle_str(data, (char *)va_arg(arg, char *));
	if (data.type == 'p')
		printed += pf_handle_address(data, va_arg(arg, void *));
	if (data.type == 'i' || data.type == 'd')
		printed += pf_handle_int(data, va_arg(arg, int));
	if (data.type == 'u')
		printed += pf_handle_unsint(data, va_arg(arg, unsigned int));
	if (data.type == 'x' || data.type == 'X')
		printed += pf_handle_hex(data, va_arg(arg, unsigned int));
	if (data.type == '%')
		printed += pf_handle_char(data, '%');
	return (printed);
}
