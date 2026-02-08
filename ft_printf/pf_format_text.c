/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:42:26 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/17 12:20:25 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_format_text(t_format data, const char *text, int len)
{
	int	printed;
	int	pad;

	printed = 0;
	pad = 0;
	if (len > data.precision && data.precision >= 0)
		len = data.precision;
	if (len < data.width)
		pad = data.width - len;
	if (data.ljustify == 0)
		printed += pf_print_padding(data.padding, pad);
	printed += write(1, text, len);
	if (data.ljustify == 1)
		printed += pf_print_padding(data.padding, pad);
	return (printed);
}
