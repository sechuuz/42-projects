/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:09:39 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/02 08:09:40 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	count(char *str)
{
	unsigned int	j;

	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	return (j);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	cl;
	unsigned int	dl;
	unsigned int	sl;

	dl = count(dest);
	sl = count(src);
	if (dl >= size)
	{
		return (size + sl);
	}
	cl = size - dl - 1;
	i = 0;
	while (i < cl && src[i] != '\0')
	{
		dest[dl + i] = src[i];
		i++;
	}
	dest[dl + i] = '\0';
	return (dl + sl);
}
