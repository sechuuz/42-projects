/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:08:13 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/30 21:36:25 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_op(char *str, char *op)
{
	int	i;

	i = 0;
	while (str[i] && op[i] && str[i] == op[i])
		i++;
	if (op[i] == '\0' && ((str[i] == '\0' || str[i] == '\n')))
		return (1);
	return (0);
}

static int	execute_swap_push(char *op, t_stack **sta, t_stack **stb)
{
	if (is_op(op, "pa"))
		stack_push(stb, sta);
	else if (is_op(op, "pb"))
		stack_push(sta, stb);
	else if (is_op(op, "sa"))
		stack_swap(sta);
	else if (is_op(op, "sb"))
		stack_swap(stb);
	else if (is_op(op, "ss"))
		stack_dualops(sta, stb, 's');
	else
		return (0);
	return (1);
}

static int	execute_rotate(char *op, t_stack **sta, t_stack **stb)
{
	if (is_op(op, "ra"))
		stack_rotate(sta);
	else if (is_op(op, "rb"))
		stack_rotate(stb);
	else if (is_op(op, "rr"))
		stack_dualops(sta, stb, 'n');
	else if (is_op(op, "rra"))
		stack_revrotate(sta);
	else if (is_op(op, "rrb"))
		stack_revrotate(stb);
	else if (is_op(op, "rrr"))
		stack_dualops(sta, stb, 'r');
	else
		return (0);
	return (1);
}

void	execute(char *op, t_stack **sta, t_stack **stb, int print)
{
	if (!execute_swap_push(op, sta, stb) && !execute_rotate(op, sta, stb))
		error_exit(sta, stb, 0, 0);
	if (print)
		ft_printf("%s\n", op);
}
