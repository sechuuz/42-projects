/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:42:16 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/12 12:42:16 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_rev(char *str)
{
	int		i;
	char	t;
	int		l;

	i = 0;
	l = ft_strlen(str);
	while (i < l / 2)
	{
		t = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = t;
		i++;
	}
}

int	ft_getnbr(int i, int s, char *nbr, char *base_from)
{
	int	j;
	int	inb;

	inb = 0;
	while (nbr[i] == ' ' || nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			s++;
		i++;
	}
	while (nbr[i] != '\0')
	{
		j = 0;
		while (j < ft_strlen(base_from) && nbr[i] != base_from[j])
			j++;
		if (j == ft_strlen(base_from))
			break ;
		inb = inb * ft_strlen(base_from) + j;
		i++;
	}
	if (s % 2 != 0)
		return (-inb);
	return (inb);
}

char	*handle_int_min(int l, int nbr, char *baset)
{
	int		i;
	char	*conbr;

	i = 1;
	conbr = malloc(34 * sizeof(char));
	conbr[0] = baset[-(nbr % l)];
	nbr = -(nbr / l);
	while (nbr > 0)
	{
		conbr[i] = baset[nbr % l];
		nbr = nbr / l;
		i++;
	}
	conbr[i++] = '-';
	conbr[i] = '\0';
	ft_rev(conbr);
	return (conbr);
}
