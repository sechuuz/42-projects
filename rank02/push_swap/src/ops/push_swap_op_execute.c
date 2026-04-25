/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:08:13 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/21 17:32:07 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute(char *op, t_stack **sta, t_stack **stb, int print)
{
	if (!ft_strcmp(op, "pa"))
		stack_push(stb, sta);
	else if (!ft_strcmp(op, "pb"))
		stack_push(sta, stb);
	else if (!ft_strcmp(op, "sa"))
		stack_swap(sta);
	else if (!ft_strcmp(op, "sb"))
		stack_swap(stb);
	else if (!ft_strcmp(op, "ss"))
		stack_dualops(sta, stb, 's');
	else if (!ft_strcmp(op, "ra"))
		stack_rotate(sta);
	else if (!ft_strcmp(op, "rb"))
		stack_rotate(stb);
	else if (!ft_strcmp(op, "rr"))
		stack_dualops(sta, stb, 'n');
	else if (!ft_strcmp(op, "rra"))
		stack_revrotate(sta);
	else if (!ft_strcmp(op, "rrb"))
		stack_revrotate(stb);
	else if (!ft_strcmp(op, "rrr"))
		stack_dualops(sta, stb, 'r');
	if (print)
		ft_printf("%s\n", op);
}