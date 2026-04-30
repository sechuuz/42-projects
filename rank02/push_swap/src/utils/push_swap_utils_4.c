/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:29:39 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/30 21:05:19 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_stack **sta, t_stack **stb)
{
	prep_move(sta, stb, (*stb)->target, 'a');
	execute("pa", sta, stb, 1);
}

void	sort_stack(t_stack **sta, t_stack **stb)
{
	int	len_a;

	len_a = ft_stacksize(*sta);
	if (len_a-- > 3 && !is_sorted(*sta))
		execute("pb", sta, stb, 1);
	if (len_a-- > 3 && !is_sorted(*sta))
		execute("pb", sta, stb, 1);
	while (len_a > 3 && !is_sorted(*sta))
	{
		init_nodes_a(*sta, *stb);
		move_to_b(sta, stb);
		len_a--;
	}
	sort_three(sta, stb);
	while (*stb)
	{
		init_nodes_b(*stb, *sta);
		move_to_a(sta, stb);
	}
	align_pos(*sta);
	min_top(sta, stb);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error_exit(t_stack **sta, t_stack **stb, char **arr, int is_split)
{
	ft_stacksfree(sta, stb);
	if (is_split && arr)
		free_arr(arr);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\0' || s1[i] != s2[i])
		{
			c1 = s1[i];
			c2 = s2[i];
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}
