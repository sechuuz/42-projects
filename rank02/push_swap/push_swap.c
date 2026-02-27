/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:08:00 by sechavez          #+#    #+#             */
/*   Updated: 2026/02/27 14:57:22 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	sort_stack(t_stack **sta, t_stack **stb)
{
	t_stack *sptr;
	int size;

	sptr = *sta;
	size = ft_stacksize(*sta);
	while(sptr && sptr->next && size > 3)
	{
		if (sptr->next && (sptr->val < sptr->next->val))
			sptr = sptr->next;
		else
		{
			stack_push(sta, stb);
			sptr = *sta;
			size--;
		}
	}
	sptr = sptr->next;
	if (sptr->val > sptr->next->val)
	{
		stack_swap(sta);
		stack_rotate(sta);
	}
	while (*stb)
		stack_push(stb, sta);
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
		read(0, input, 4);
		if (!(ft_strncmp(input, "pb", 2)))			
			stack_push(&sta, &stb);
		else if (!(ft_strncmp(input, "pa", 2)))
			stack_push(&stb, &sta);
		else if (!(ft_strncmp(input, "sa", 2)))
			stack_swap(&sta);
		else if (!(ft_strncmp(input, "sb", 2)))
			stack_swap(&stb);
		else if (!(ft_strncmp(input, "ra", 2)))
			stack_rotate(&sta);
		else if (!(ft_strncmp(input, "rb", 2)))
			stack_rotate(&stb);
		else if (!(ft_strncmp(input, "rra", 3)))
			stack_revrotate(&sta);
		else if (!(ft_strncmp(input, "rrb", 3)))
			stack_revrotate(&stb);
		else if (!(ft_strncmp(input, "ch", 2)))
			sort_stack(&sta, &stb);
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