/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:24:24 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/10 16:42:08 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_padding(char pad, int len)
{
	int	printed;

	printed = 0;
	while (len > 0)
	{
		write(1, &pad, 1);
		len--;
		printed++;
	}
	return (printed);
}
