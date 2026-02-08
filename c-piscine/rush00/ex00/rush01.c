/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:37:36 by mfarhan           #+#    #+#             */
/*   Updated: 2025/07/06 23:23:20 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int x, int y, int row, int column)
{
	column = 1;
	while (column <= x)
	{
		if (column == 1 && row == 1)
			ft_putchar('/');
		else if (column == x && row == 1)
			ft_putchar('\\');
		else if (column == 1 && row == y)
			ft_putchar('\\');
		else if (column == x && row == y)
			ft_putchar('/');
		else if (column == x || row == y
			|| column == 1 || row == 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
		column++;
	}
}

void	rush(int x, int y)
{
	int	column;
	int	row;

	row = 1;
	while (row <= y)
	{
		column = 1;
		ft_print(x, y, row, column);
		ft_putchar('\n');
		row++;
	}
}
