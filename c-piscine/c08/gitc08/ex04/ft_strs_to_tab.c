/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:13:37 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/14 15:13:37 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*strcs;

	i = 0;
	strcs = malloc((ac + 1) * sizeof(t_stock_str));
	if (!strcs)
		return (0);
	while (i < ac)
	{
		strcs[i].str = av[i];
		strcs[i].size = ft_strlen(av[i]);
		strcs[i].copy = ft_strdup(av[i]);
		i++;
	}
	strcs[i].str = 0;
	strcs[i].size = 0;
	strcs[i].copy = 0;
	return (strcs);
}
