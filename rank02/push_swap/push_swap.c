/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:08:00 by sechavez          #+#    #+#             */
/*   Updated: 2026/02/23 15:15:10 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

void	push(t_stack **sta, t_stack **stb)
{
	t_stack *sptr;
	
	sptr = *sta;

	*sta = sptr->next;
	(*sta)->prev = 0;

	sptr->next = *stb;
	sptr->prev = 0;

	if (*stb)
		(*stb)->prev = sptr;

	*stb = sptr;
}

void	swap(t_stack **sta)
{
	t_stack *sptr;
	t_stack *sptr2;

	sptr = *sta;
	sptr2 = sptr->next;

	sptr->next = sptr2->next;
	sptr2->next->prev = sptr;
	sptr2->next = sptr;
	*sta = sptr2;
}

int main(int count, char* string[])
{
	int		i = 1;
	char	input[100];

	t_stack *sta;
	t_stack *stb;
	t_stack *sptr;

	sptr = ft_stacknew(atoi(string[i]), i);
	i++;
	sta = sptr;
	stb = 0;
	while (i < count)
	{
		sptr->next = ft_stacknew(atoi(string[i]), i);
		sptr->next->prev = sptr;
		sptr = sptr->next;
		i++;
	}
	while (1)
	{
		read(0, input, 3);
		if (!(ft_strncmp(input, "pb", 2)))
		{
			push(&sta, &stb);
		}
		else if (!(ft_strncmp(input, "pa", 2)))
		{
			push(&stb, &sta);
		}
		else if (!(ft_strncmp(input, "sa", 2)))
		{
			swap(&sta);
		}
		else if (!(ft_strncmp(input, "sb", 2)))
		{
			swap(&stb);
		}
		i = 1;
		sptr = sta;
		while (sptr)
		{
			ft_printf("%d (%d) - ", sptr->val, sptr->index);
			sptr = sptr->next;
			i++;
		}
		ft_printf("\n");
		i = 1;
		sptr = stb;
		while (sptr)
		{
			ft_printf("%d (%d) - ", sptr->val, sptr->index);
			sptr = sptr->next;
			i++;
		}
		ft_printf("\n");
	}
	return (1);
}