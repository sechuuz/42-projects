/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:38:23 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 19:27:24 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while ((i + j < len)
			&& (haystack[i + j] == needle[j]) && (needle[j] != '\0'))
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)&haystack[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
