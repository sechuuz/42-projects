/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:17:23 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/05 16:17:24 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	basenbr(int l, int nbr, char *base)
{
	int	c;

	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		c = base[-(nbr % l)];
		nbr = -(nbr / l);
		if (nbr >= l)
		{
			basenbr(l, nbr, base);
		}
		write(1, &c, 1);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= l)
	{
		basenbr(l, nbr / l, base);
	}
	c = base[nbr % l];
	write(1, &c, 1);
}

int	checkbase(int i, char *base)
{
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[i] != '\0')
		{
			j = i + 1;
			while (base[j] != '\0')
			{
				if (base[i] == base[j])
				{
					return (0);
				}
				j++;
			}
			if (base[i] == '-' || base[i] == '+')
			{
				return (0);
			}
			i++;
		}
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;

	l = checkbase(0, base);
	if (l > 1)
	{
		basenbr(l, nbr, base);
	}
}
