/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:55:42 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 19:10:47 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	l;
	size_t	i;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	i = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	while (i < len && s[start] != '\0')
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
