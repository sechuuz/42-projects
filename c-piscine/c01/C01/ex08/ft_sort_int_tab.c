/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:49:05 by sechavez          #+#    #+#             */
/*   Updated: 2025/06/30 12:49:08 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	b_swap(int *a, int *b, int *s)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
	*s = 1;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	while (i < size - 1)
	{
		s = 0;
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				b_swap(&tab[j], &tab[j + 1], &s);
			}
			j++;
		}
		i++;
	}
}
