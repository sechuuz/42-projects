/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:11:46 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/16 11:11:46 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	write_num(int nb)
{
	char	i;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		write_num(nb / 10);
	}
	i = nb % 10 + '0';
	write(1, &i, 1);
}

void	write_tab(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write_tab(par[i].str);
		write(1, "\n", 1);
		write_num(par[i].size);
		write(1, "\n", 1);
		write_tab(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
