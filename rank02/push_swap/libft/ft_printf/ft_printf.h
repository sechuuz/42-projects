/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:33:52 by sechavez          #+#    #+#             */
/*   Updated: 2026/02/23 12:50:53 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
{
	int		width;
	int		precision;
	int		ljustify;
	char	padding;
	char	prefix;
	char	type;
}	t_format;

int			ft_printf(const char *format, ...);
t_format	pf_parse_format(const char *format, int *chars_eaten);
int			pf_check_format(t_format data, va_list arg);
int			pf_handle_char(t_format data, const char c);
int			pf_handle_str(t_format data, char *c);
int			pf_handle_address(t_format data, void *c);
int			pf_handle_int(t_format data, int n);
int			pf_handle_unsint(t_format data, unsigned int n);
int			pf_handle_hex(t_format data, unsigned int n);
int			pf_print_padding(char pad, int len);
int			bufitoa(char *buf, long long n);
int			bufuhextoa(char *buf, unsigned long long num, const char *hex);
int			pf_format_text(t_format data, const char *text, int len);
int			pf_format_num(t_format data, const char *num, char sign, int len);

#endif