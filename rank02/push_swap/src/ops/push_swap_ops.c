/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:32:25 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/21 17:29:54 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack **sta)
{
	t_stack	*sptr;
	t_stack	*sptr2;

	if (!(*sta) || !sta || !(*sta)->next)
		return ;
	sptr = *sta;
	sptr2 = sptr->next;
	if (sptr2->next)
	{
		sptr->next = sptr2->next;
		sptr2->next->prev = sptr;
	}
	else
		sptr->next = 0;
	sptr2->next = sptr;
	sptr2->prev = 0;
	sptr->prev = sptr2;
	*sta = sptr2;
}

void	stack_push(t_stack **sta, t_stack **stb)
{
	t_stack	*sptr;

	if (!(*sta) || !sta)
		return ;
	sptr = *sta;
	*sta = sptr->next;
	if (*sta)
		(*sta)->prev = 0;
	sptr->next = *stb;
	if (sptr->prev)
		sptr->prev = 0;
	if (*stb)
		(*stb)->prev = sptr;
	*stb = sptr;
}

void	stack_rotate(t_stack **sta)
{
	t_stack	*sptr;

	if (!(*sta) || !sta || !(*sta)->next)
		return ;
	sptr = *sta;
	*sta = sptr->next;
	(*sta)->prev = 0;
	sptr->prev = ft_stacklast(*sta);
	sptr->next = 0;
	sptr->prev->next = sptr;
}

void	stack_revrotate(t_stack **sta)
{
	t_stack	*sptr;

	if (!(*sta) || !sta || !(*sta)->next)
		return ;
	sptr = ft_stacklast(*sta);
	sptr->prev->next = 0;
	sptr->prev = 0;
	sptr->next = *sta;
	(*sta)->prev = sptr;
	*sta = sptr;
}

void	stack_dualops(t_stack **sta, t_stack **stb, char type)
{
	if (type == 's')
	{
		stack_swap(sta);
		stack_swap(stb);
	}
	else if (type == 'n')
	{
		stack_rotate(sta);
		stack_rotate(stb);
	}
	else if (type == 'r')
	{
		stack_revrotate(sta);
		stack_revrotate(stb);
	}
}
