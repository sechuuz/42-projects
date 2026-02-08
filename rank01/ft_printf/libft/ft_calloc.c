/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:00:32 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/20 12:16:38 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	fs;
	void	*f;

	if (size != 0 && count > (INT_MAX / size))
		return (0);
	fs = count * size;
	f = malloc(fs);
	if (!f)
		return (0);
	ft_bzero(f, fs);
	return (f);
}
