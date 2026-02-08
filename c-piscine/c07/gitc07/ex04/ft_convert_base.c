/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:42:14 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/12 12:42:14 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_rev(char *str);
int		ft_getnbr(int i, int s, char *nbr, char *basef);
char	*handle_int_min(int l, int nbr, char *baset);

char	*ft_convbase(int isn, int l, int nbr, char *baset)
{
	int		i;
	char	*conbr;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (handle_int_min(l, nbr, baset));
		isn = 1;
		nbr = -nbr;
	}
	conbr = malloc(34 * sizeof(char));
	i = 0;
	if (nbr == 0)
		conbr[i++] = baset[0];
	while (nbr > 0)
	{
		conbr[i] = baset[nbr % l];
		nbr = nbr / l;
		i++;
	}
	if (isn == 1)
		conbr[i++] = '-';
	conbr[i] = '\0';
	ft_rev(conbr);
	return (conbr);
}

int	ft_checkbase(char *base)
{
	int		i;
	int		seen[128];

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (i < 128)
		seen[i++] = 0;
	i = 0;
	while (base[i])
	{
		if ((seen[(unsigned char)base[i]] != 0) || (base[i] == '-'
				|| base[i] == '+' || base[i] == ' '))
			return (0);
		if (seen[(unsigned char)base[i]] == 0)
			seen[(unsigned char)base[i]]++;
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		inb;
	char	*ifnull;

	if (nbr == 0 || base_from == 0 || base_to == 0)
	{
		ifnull = malloc(1);
		ifnull[0] = '\0';
		return (ifnull);
	}
	if (!ft_checkbase(base_from) || !ft_checkbase(base_to))
		return (0);
	inb = ft_getnbr(0, 0, nbr, base_from);
	return (ft_convbase(0, ft_strlen(base_to), inb, base_to));
}
