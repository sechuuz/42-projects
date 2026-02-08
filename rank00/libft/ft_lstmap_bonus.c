/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:57:27 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 19:16:03 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*c;
	t_list	*n;
	void	*h;

	if (!lst || !f || !del)
		return (0);
	n = 0;
	while (lst != 0)
	{
		h = f(lst->content);
		c = ft_lstnew(h);
		if (!c)
		{
			ft_lstclear(&n, del);
			return (0);
		}
		ft_lstadd_back(&n, c);
		lst = lst->next;
	}
	return (n);
}
