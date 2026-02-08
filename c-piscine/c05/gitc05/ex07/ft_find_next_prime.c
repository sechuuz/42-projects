/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:34:45 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/07 19:34:46 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb)
{
	int	i;
	int	p;

	i = 1;
	p = 0;
	while (i <= (nb / 2))
	{
		if (nb % i == 0)
			p++;
		i++;
	}
	if (p == 1)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
