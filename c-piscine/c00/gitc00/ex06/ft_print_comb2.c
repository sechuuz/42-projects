/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:50:21 by sechavez          #+#    #+#             */
/*   Updated: 2025/06/25 17:50:22 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	br_write(int i)
{
	int	t;
	int	u;

	t = i / 10 + '0';
	u = i % 10 + '0';
	write(1, &t, 1);
	write(1, &u, 1);
}

void	comb_write(int a, int b)
{
	br_write(a);
	write(1, " ", 1);
	br_write(b);
	if (!(a == 98 && b == 99))
	{
		write(1, ", ", 2);
		if (b < 99)
		{
			comb_write(a, b + 1);
		}
		else if (a < 98)
		{
			comb_write(a + 1, a + 2);
		}
	}
}

void	ft_print_comb2(void)
{
	comb_write(0, 1);
}
