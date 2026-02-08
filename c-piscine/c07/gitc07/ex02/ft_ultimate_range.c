/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:45:17 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/09 17:45:18 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	*range = malloc((max - min) * sizeof(int));
	if (min >= max || *range == 0)
	{
		*range = 0;
		return (0);
	}
	i = 0;
	while (min < max)
		(*range)[i++] = min++;
	return (i);
}
