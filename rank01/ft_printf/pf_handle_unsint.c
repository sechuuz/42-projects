/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_unsint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:49:56 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/10 18:51:17 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_handle_unsint(t_format data, unsigned int n)
{
	int		len;
	char	buf[32];

	len = bufitoa(buf, (long long)n);
	return (pf_format_num(data, buf, data.prefix, len));
}
