/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:14:28 by sechavez          #+#    #+#             */
/*   Updated: 2026/04/21 17:42:15 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				val;
	int				index;
	int				pos;
	int				cost;
	int				above_median;
	int				is_cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int val, int index);
t_stack	*ft_stacklast(t_stack *lst);
int		ft_stacksize(t_stack *sta);
void	stack_swap(t_stack **sta);
void	stack_push(t_stack **sta, t_stack **stb);
void	stack_rotate(t_stack **sta);
void	stack_revrotate(t_stack **sta);
void	stack_dualops(t_stack **sta, t_stack **stb, char type);
void	sort_stack(t_stack **sta, t_stack **stb);
void	ft_stackfree(t_stack **sta);
void	ft_stackadd_back(t_stack **sta, t_stack *new);
int		ft_strcmp(const char *s1, const char *s2);
void	execute(char *op, t_stack **sta, t_stack **stb, int print);
void	sort_three(t_stack **sta, t_stack **stb);
int		is_sorted(t_stack *sta);
t_stack	*find_min(t_stack *sta);
t_stack	*find_max(t_stack *sta);
void	min_top(t_stack **sta, t_stack **stb);
t_stack	*get_cheapest(t_stack *sta);
void	set_cheapest(t_stack *sta);
void	set_price(t_stack *sta, t_stack *stb);
void	set_target_b(t_stack *sta, t_stack *stb);
void	set_target_a(t_stack *sta, t_stack *stb);
void	align_pos(t_stack *sta);
void	init_nodes_a(t_stack *sta, t_stack *stb);
void	init_nodes_b(t_stack *stb, t_stack *sta);
void	prep_move(t_stack **sta, t_stack **stb, t_stack *top, char stack);
void	move_to_b(t_stack **sta, t_stack **stb);
void	move_to_a(t_stack **sta, t_stack **stb);
void	sort_stack(t_stack **sta, t_stack **stb);
void	error_exit(t_stack **sta, t_stack **stb);
int		validity_check(const char *str);
int		build_nodes(t_stack **sta, int count, char *string[]);
int		has_duplicates(t_stack *sta);

#endif
