/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:20:42 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/04 15:20:45 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	atoic(int i, int s, int n, char *str)
{
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (s % 2 != 0)
	{
		n = -n;
	}
	return (n);
}

int	ft_atoi(char *str)
{
	return (atoic(0, 0, 0, str));
}
