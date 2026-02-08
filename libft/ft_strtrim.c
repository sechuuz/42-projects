/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:19:54 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/20 14:02:45 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	j;
	int		k;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (isinset(s1[i], set) == 1)
		i++;
	j = ft_strlen(s1);
	while (j > i && isinset(s1[j - 1], set) == 1)
		j--;
	s2 = malloc(((j - i) + 1) * sizeof(char));
	if (!s2)
		return (0);
	k = 0;
	while (i < j)
	{
		s2[k] = s1[i];
		k++;
		i++;
	}
	s2[k] = '\0';
	return (s2);
}
