/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:14:28 by sechavez          #+#    #+#             */
/*   Updated: 2026/02/23 13:22:04 by sechavez         ###   ########.fr       */
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

#endif
