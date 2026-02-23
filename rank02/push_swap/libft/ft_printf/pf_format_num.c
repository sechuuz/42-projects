/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:51:48 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/11 17:14:06 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_handle_sign(t_format data, char sign, const char *num, int len)
{
	int	printed;

	printed = 0;
	if (data.prefix == '#' && (data.type == 'x' || data.type == 'X')
		&& !(len == 1 && num[0] == '0'))
	{
		if (data.type == 'x')
			printed += write(1, "0x", 2);
		else if (data.type == 'X')
			printed += write(1, "0X", 2);
	}
	else if (data.type == 'p')
		printed += write(1, "0x", 2);
	else if (sign != 0)
		printed += write(1, &sign, 1);
	return (printed);
}

static void	pf_init_var(t_format data, char sign, int *pad, int *signlen)
{
	*pad = 0;
	*signlen = 0;
	if (data.type == 'p')
		*signlen = 2;
	else if ((data.prefix != 0 || sign != 0) && data.prefix != '#')
		*signlen = 1;
	else if (data.prefix == '#')
		*signlen = 2;
	else
		*signlen = 0;
}

int	pf_format_num(t_format data, const char *num, char sign, int len)
{
	int	printed;
	int	zeros;
	int	pad;
	int	signlen;

	printed = 0;
	zeros = 0;
	pf_init_var(data, sign, &pad, &signlen);
	if (data.precision == 0 && num[0] == '0')
		len = 0;
	if (len < data.precision)
		zeros = data.precision - len;
	if (len + zeros < data.width)
		pad = data.width - (len + zeros) - signlen;
	if (data.padding == '0' && sign != 0)
		printed += pf_handle_sign(data, sign, num, len);
	if (data.ljustify == 0)
		printed += pf_print_padding(data.padding, pad);
	if ((data.padding == ' ' && sign != 0) || data.type == 'p')
		printed += pf_handle_sign(data, sign, num, len);
	printed += pf_print_padding('0', zeros);
	printed += write(1, num, len);
	if (data.ljustify == 1)
		printed += pf_print_padding(data.padding, pad);
	return (printed);
}
