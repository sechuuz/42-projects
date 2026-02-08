/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:59:57 by sechavez          #+#    #+#             */
/*   Updated: 2025/06/27 14:00:00 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	comb_print(int comb[], int n)
{
	int	i;
	int	c;

	i = 0;
	while (i < n)
	{
		c = comb[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (comb[0] != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	comb_generate(int n, int comb[], int i, int s)
{
	int	d;

	d = s;
	while (d <= 9)
	{
		comb[i] = d;
		if (i == n - 1)
		{
			comb_print(comb, n);
		}
		else
		{
			comb_generate(n, comb, i + 1, d + 1);
		}
		d++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];

	comb_generate(n, comb, 0, 0);
}
