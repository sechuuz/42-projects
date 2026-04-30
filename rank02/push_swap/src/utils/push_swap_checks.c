/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:46:19 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/30 21:26:15 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validity_check(const char *str)
{
	long	n;
	int		s;
	int		i;

	n = 0;
	s = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			s = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i++] - '0');
		if ((s * n) > 2147483647 || (s * n) < -2147483648)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	build_nodes(t_stack **sta, char *string[], int is_split)
{
	int		i;
	t_stack	*new;

	i = !is_split;
	while (string[i])
	{
		if (!validity_check(string[i]))
			return (0);
		new = ft_stacknew(atoi(string[i]), i);
		if (!new)
			return (0);
		ft_stackadd_back(sta, new);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *sta)
{
	t_stack	*slow;
	t_stack	*fast;

	slow = sta;
	while (slow)
	{
		fast = slow->next;
		while (fast)
		{
			if (slow->val == fast->val)
				return (1);
			fast = fast->next;
		}
		slow = slow->next;
	}
	return (0);
}
