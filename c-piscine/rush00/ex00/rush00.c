/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:37:32 by mfarhan           #+#    #+#             */
/*   Updated: 2025/07/06 22:46:59 by mfarhan          ###   ########.fr       */
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
			if (((column == 1 && row == 1) || (column == 1 && row == y))
				|| ((column == x && row == 1) || (column == x && row == y)))
				ft_putchar('o');
			else if ((row == 1 || row == y) && (column > 1 && column < x))
				ft_putchar('-');
			else if ((column == 1 || column == x) && (row > 1 && row < y))
				ft_putchar('|');
			else
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
