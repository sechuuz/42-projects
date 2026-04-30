/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:29:39 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/30 17:47:10 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *sta)
{
	while (sta)
	{
		if (sta->is_cheapest)
			return (sta);
		sta = sta->next;
	}
	return (0);
}

void	set_cheapest(t_stack *sta)
{
	t_stack	*cheapest_node;
	t_stack	*curr;
	int		cheapest_val;

	if (!sta)
		return ;
	curr = sta;
	while (curr)
	{
		curr->is_cheapest = 0;
		curr = curr->next;
	}
	cheapest_node = 0;
	cheapest_val = INT_MAX;
	while (sta)
	{
		if (sta->cost < cheapest_val)
		{
			cheapest_val = sta->cost;
			cheapest_node = sta;
		}
		sta = sta->next;
	}
	cheapest_node->is_cheapest = 1;
}

void	set_price(t_stack *sta, t_stack *stb)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacksize(sta);
	len_b = ft_stacksize(stb);
	while (sta)
	{
		if (sta->above_median)
			sta->cost = sta->pos;
		else
			sta->cost = len_a - sta->pos;
		if (sta->target->above_median)
			sta->cost += sta->target->pos;
		else
			sta->cost += len_b - sta->target->pos;
		sta = sta->next;
	}
}

void	set_target_b(t_stack *sta, t_stack *stb)
{
	t_stack	*curr_b;
	t_stack	*target_node;
	int		best_match;

	while (sta)
	{
		best_match = INT_MAX;
		curr_b = stb;
		while (curr_b)
		{
			if (curr_b->val > sta->val && curr_b->val < best_match)
			{
				best_match = curr_b->val;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == INT_MAX)
			sta->target = find_min(stb);
		else
			sta->target = target_node;
		sta = sta->next;
	}
}

void	set_target_a(t_stack *sta, t_stack *stb)
{
	t_stack	*curr_b;
	t_stack	*target_node;
	int		best_match;

	while (sta)
	{
		best_match = INT_MIN;
		curr_b = stb;
		while (curr_b)
		{
			if (curr_b->val < sta->val && curr_b->val > best_match)
			{
				best_match = curr_b->val;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == INT_MIN)
			sta->target = find_max(stb);
		else
			sta->target = target_node;
		sta = sta->next;
	}
}
