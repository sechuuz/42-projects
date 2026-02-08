/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:13:36 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/12 18:17:38 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_is_flag(const char c)
{
	char	flags[6];
	int		i;

	i = 0;
	ft_strlcpy(flags, "0-# +", 6);
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	pf_scan_digit(int *dig, const char **c, int *chars_eaten)
{
	int		i;

	*dig = 0;
	i = 0;
	while ((**c) >= '0' && (**c) <= '9')
	{
		*dig = *dig * 10 + (**c - '0');
		(*chars_eaten)++;
		i++;
		(*c)++;
	}
}

static void	pf_scan_type(t_format *new, const char c, int *chars_eaten)
{
	char	types[10];
	int		i;

	i = 0;
	ft_strlcpy(types, "cspdiuxX%", 10);
	while (types[i])
	{
		if (types[i] == c)
		{
			new->type = c;
			(*chars_eaten)++;
			break ;
		}
		i++;
	}
}

static void	init_zero(t_format *new, int *chars_eaten)
{
	*chars_eaten = 0;
	new->width = 0;
	new->precision = -1;
	new->ljustify = 0;
	new->padding = ' ';
	new->prefix = 0;
	new->type = 0;
}

t_format	pf_parse_format(const char *format, int *chars_eaten)
{
	t_format	new;

	init_zero(&new, chars_eaten);
	while (pf_is_flag(*format))
	{
		if (*format == '0' && !new.ljustify)
			new.padding = *format;
		if (*format == '-')
			new.ljustify = 1;
		if (*format == '+' || *format == '#')
			new.prefix = *format;
		if (*format == ' ' && new.prefix != '+')
			new.prefix = *format;
		(*chars_eaten)++;
		format++;
	}
	pf_scan_digit(&new.width, &format, chars_eaten);
	if (*format == '.')
	{
		(*chars_eaten)++;
		format++;
		pf_scan_digit(&new.precision, &format, chars_eaten);
	}
	pf_scan_type(&new, *format, chars_eaten);
	return (new);
}
