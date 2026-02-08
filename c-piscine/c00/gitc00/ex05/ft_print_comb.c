/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:23:44 by sechavez          #+#    #+#             */
/*   Updated: 2025/06/25 17:23:46 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb_write(int i, int j, int k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (!(i == '7' && j == '8' && k == '9'))
	{
		write(1, ", ", 2);
		if (k < '9')
		{
			ft_print_comb_write(i, j, k + 1);
		}
		else if (j < '8')
		{
			ft_print_comb_write(i, j + 1, j + 2);
		}
		else
		{
			ft_print_comb_write(i + 1, i + 2, i + 3);
		}
	}
}

void	ft_print_comb(void)
{
	ft_print_comb_write('0', '1', '2');
}
