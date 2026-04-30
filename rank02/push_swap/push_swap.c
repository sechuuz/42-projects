/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:08:00 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/30 21:28:01 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**init_args(int count, char *string[], int *is_split)
{
	if (count == 2)
	{
		*is_split = 1;
		return (ft_split(string[1], ' '));
	}
	*is_split = 0;
	return (string);
}

static void	tiny_sort(t_stack **sta, t_stack **stb)
{
	if (!is_sorted(*sta))
		execute("sa", sta, stb, 1);
}

int	main(int count, char *string[])
{
	t_stack	*sta;
	t_stack	*stb;
	char	**arr;
	int		is_split;
	int		size;

	if (count < 2)
		return (0);
	sta = 0;
	stb = 0;
	arr = init_args(count, string, &is_split);
	if (!build_nodes(&sta, arr, is_split))
		error_exit(&sta, &stb, arr, is_split);
	if (has_duplicates(sta))
		error_exit(&sta, &stb, arr, is_split);
	size = ft_stacksize(sta);
	if (size < 3)
		tiny_sort(&sta, &stb);
	else if (!is_sorted(sta))
		sort_stack(&sta, &stb);
	ft_stacksfree(&sta, &stb);
	if (is_split)
		free_arr(arr);
	return (0);
}
