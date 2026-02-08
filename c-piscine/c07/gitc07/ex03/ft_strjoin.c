/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:04:31 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/09 18:04:32 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}

char	*ft_stradd(int *i, char *dest, char *src)
{
	int	k;

	k = 0;
	while (src[k])
		dest[(*i)++] = src[k++];
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		tl;
	char	*jstr;

	if (size == 0)
		return (malloc(1));
	i = 0;
	tl = 0;
	while (i < size)
		tl += ft_strlen(strs[i++]);
	tl += ft_strlen(sep) * (size - 1);
	jstr = malloc((tl + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_stradd(&j, jstr, strs[i]);
		if (i < size - 1)
			ft_stradd(&j, jstr, sep);
		i++;
	}
	jstr[j] = '\0';
	return (jstr);
}
