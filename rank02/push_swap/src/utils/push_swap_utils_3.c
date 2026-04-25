/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:29:39 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/21 17:54:45 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_pos(t_stack *sta)
{
	int	i;
	int	mid;

	i = 0;
	mid = ft_stacksize(sta) / 2;
	while (sta)
	{
		sta->pos = i;
		sta->above_median = (i <= mid);
		sta = sta->next;
		i++;
	}
}

void	init_nodes_a(t_stack *sta, t_stack *stb)
{
	align_pos(sta);
	align_pos(stb);
	set_target_a(sta, stb);
	set_price(sta, stb);
	set_cheapest(sta);
}

void	init_nodes_b(t_stack *stb, t_stack *sta)
{
	align_pos(sta);
	align_pos(stb);
	set_target_b(stb, sta);
}

void	prep_move(t_stack **sta, t_stack **stb, t_stack *top, char stack)
{
	while (*sta != top)
	{
		if (stack == 'a')
		{
			if (top->above_median)
				execute("ra", sta, stb, 1);
			else
				execute("rra", sta, stb, 1);
		}
		else
		{
			if (top->above_median)
				execute("rb", stb, sta, 1);
			else
				execute("rrb", stb, sta, 1);
		}
	}
}

void	move_to_b(t_stack **sta, t_stack **stb)
{
	t_stack	*cheapest;

	cheapest = get_cheapest((*sta));
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*sta != cheapest && *stb != cheapest->target)
			execute("rr", sta, stb, 1);
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*sta != cheapest && *stb != cheapest->target)
			execute("rrr", sta, stb, 1);
	}
	align_pos(*sta);
	align_pos(*stb);
	prep_move(sta, stb, cheapest, 'a');
	prep_move(stb, sta, cheapest->target, 'b');
	execute("pb", sta, stb, 1);
}
