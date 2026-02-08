/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:20:14 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/09 13:20:14 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ia;

	ia = malloc((max - min) * sizeof(int));
	if (min >= max || ia == NULL)
		return (0);
	i = 0;
	while (min < max)
	{
		ia[i++] = min++;
	}
	return (ia);
}
