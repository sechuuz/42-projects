/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:36:25 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/10 16:48:23 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_handle_str(t_format data, char *c)
{
	if (!c)
		c = "(null)";
	return (pf_format_text(data, c, ft_strlen(c)));
}
