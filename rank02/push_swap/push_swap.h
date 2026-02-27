/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:14:28 by sechavez          #+#    #+#             */
/*   Updated: 2026/02/27 15:55:02 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int             val;
    int             index;
    struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int val, int index);
t_stack	*ft_stacklast(t_stack *lst);
int     ft_stacksize(t_stack *sta);
void	stack_swap(t_stack **sta);
void	stack_push(t_stack **sta, t_stack **stb);
void	stack_rotate(t_stack **sta);
void	stack_revrotate(t_stack **sta);
void	sort_stack(t_stack **sta, t_stack **stb);

#endif
