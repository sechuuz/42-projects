/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:35:55 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/30 21:35:26 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_ok(t_stack *sta, t_stack *stb)
{
	if (is_sorted(sta) && stb == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static char	**init_args(int count, char *string[], int *is_split)
{
	if (count == 2)
	{
		*is_split = 1;
		return (ft_split(string[1], ' '));
	}
	*is_split = 0;
	return (string);
}

int	main(int count, char *string[])
{
	t_stack	*sta;
	t_stack	*stb;
	char	**arr;
	char	*op;
	int		is_split;

	if (count < 2)
		return (0);
	sta = 0;
	stb = 0;
	arr = init_args(count, string, &is_split);
	if (!build_nodes(&sta, arr, is_split))
		error_exit(&sta, &stb, arr, is_split);
	if (has_duplicates(sta))
		error_exit(&sta, &stb, arr, is_split);
	op = get_next_line(0);
	while (op)
	{
		execute(op, &sta, &stb, 0);
		free(op);
		op = get_next_line(0);
	}
	check_ok(sta, stb);
	ft_stacksfree(&sta, &stb);
	return (0);
}
