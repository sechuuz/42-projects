/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:35:55 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/29 20:39:26 by sechavez         ###   ########.fr       */
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

int	main(int count, char *string[])
{
	t_stack	*sta;
	t_stack	*stb;
	char	*op;

	sta = 0;
	stb = 0;
	if (count < 2)
		return (0);
	if (!build_nodes(&sta, count, string))
		error_exit(&sta, &stb);
	if (has_duplicates(sta))
		error_exit(&sta, &stb);
	op = get_next_line(0);
	while (op)
	{
		execute(op, &sta, &stb, 0);
		free(op);
		op = get_next_line(0);
	}
	check_ok(sta, stb);
	ft_stackfree(&sta);
	ft_stackfree(&stb);
	return (0);
}
