/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:34:11 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/11 17:51:21 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			chars_eaten;
	int			printed;
	t_format	data;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			data = pf_parse_format(format, &chars_eaten);
			printed += pf_check_format(data, args);
			format += chars_eaten;
		}
		else
		{
			write(1, format, 1);
			printed++;
			format++;
		}
	}
	va_end(args);
	return (printed);
}
