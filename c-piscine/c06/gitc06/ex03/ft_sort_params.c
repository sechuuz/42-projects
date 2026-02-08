/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:32:17 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/08 09:32:18 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	b_swap(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

void	arg_write(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	s;

	s = 0;
	while (!s)
	{
		s = 1;
		i = 1;
		while (i < argc - 1)
		{
			j = 0;
			while (argv[i][j] == argv[i + 1][j])
				j++;
			if (argv[i][j] > argv[i + 1][j])
			{
				b_swap(&argv[i], &argv[i + 1]);
				s = 0;
			}
			i++;
		}
	}
	arg_write(argc, argv);
}
