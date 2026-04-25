/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:27:31 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/21 17:41:44 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **sta, t_stack **stb)
{
	int	a;
	int	b;
	int	c;

	a = (*sta)->val;
	b = (*sta)->next->val;
	c = (*sta)->next->next->val;
	if (a > b && b < c && a < c)
		execute("sa", sta, stb, 1);
	else if (a > b && b > c)
	{
		execute("sa", sta, stb, 1);
		execute("rra", sta, stb, 1);
	}
	else if (a > b && b < c && a > c)
		execute("ra", sta, stb, 1);
	else if (a < b && b > c && a < c)
	{
		execute("sa", sta, stb, 1);
		execute("ra", sta, stb, 1);
	}
	else if (a < b && b > c && a > c)
		execute("rra", sta, stb, 1);
}

int	is_sorted(t_stack *sta)
{
	if (!sta)
		return (1);
	while (sta->next)
	{
		if (sta->val == sta->next->val)
			return (2);
		if (sta->val > sta->next->val)
			return (0);
		sta = sta->next;
	}
	return (1);
}

t_stack	*find_min(t_stack *sta)
{
	int		min;
	t_stack	*min_node;

	if (!sta)
		return (0);
	min_node = 0;
	min = INT_MAX;
	while (sta)
	{
		if (sta->val < min)
		{
			min = sta->val;
			min_node = sta;
		}
		sta = sta->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *sta)
{
	int		max;
	t_stack	*max_node;

	if (!sta)
		return (0);
	max_node = 0;
	max = INT_MIN;
	while (sta)
	{
		if (sta->val > max)
		{
			max = sta->val;
			max_node = sta;
		}
		sta = sta->next;
	}
	return (max_node);
}

void	min_top(t_stack **sta, t_stack **stb)
{
	t_stack	*min;

	min = find_min(*sta);
	while (*sta != min)
	{
		if (min->above_median)
			execute("ra", sta, stb, 1);
		else
			execute("rra", sta, stb, 1);
	}
}
