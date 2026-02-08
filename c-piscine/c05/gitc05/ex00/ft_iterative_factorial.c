/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:11:37 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/06 05:11:38 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	r;
	int	s;

	s = 1;
	if (nb < 0)
	{
		return (0);
	}
	r = 1;
	while (nb > 0)
	{
		s *= nb;
		nb--;
	}
	return (s);
}
