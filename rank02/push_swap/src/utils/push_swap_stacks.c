/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:34:54 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/21 15:27:42 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int val, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->val = val;
	new->index = index;
	new->prev = 0;
	new->next = 0;
	return (new);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*t;

	if (!lst)
		return (0);
	t = lst;
	while (t->next != 0)
		t = t->next;
	return (t);
}

int	ft_stacksize(t_stack *sta)
{
	int	i;

	if (!sta)
		return (0);
	i = 1;
	while (sta->next != 0)
	{
		sta = sta->next;
		i++;
	}
	return (i);
}

void	ft_stackfree(t_stack **sta)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!sta || !(*sta))
		return ;
	curr = *sta;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*sta = 0;
}

void	ft_stackadd_back(t_stack **sta, t_stack *new)
{
	t_stack	*last;

	if (!sta || !new)
		return ;
	if (!(*sta))
	{
		*sta = new;
		return ;
	}
	last = *sta;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}
