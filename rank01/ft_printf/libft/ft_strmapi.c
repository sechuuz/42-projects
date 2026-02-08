/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:21:41 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 19:13:23 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*ns;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	ns = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!ns)
		return (0);
	while (s[i] != '\0')
	{
		ns[i] = (*f)(i, s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
