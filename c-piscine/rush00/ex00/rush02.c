/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:37:38 by mfarhan           #+#    #+#             */
/*   Updated: 2025/07/06 22:31:09 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	column;
	int	row;

	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			if ((column == 1 && row == 1) || (column == x && row == 1))
				ft_putchar('A');
			else if ((column == 1 && row == y) || (column == x && row == y))
				ft_putchar('C');
			else if (column == 1 || row == 1 || column == x || row == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
