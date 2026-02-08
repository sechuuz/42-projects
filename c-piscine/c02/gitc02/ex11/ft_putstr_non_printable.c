/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:41:08 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/01 21:41:09 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	hexa(char c)
{
	int		t;
	int		u;
	char	*hex;

	hex = "0123456789abcdef";
	t = c / 16;
	u = c % 16;
	write(1, "\\", 1);
	write(1, &hex[t], 1);
	write(1, &hex[u], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
		{
			hexa(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
