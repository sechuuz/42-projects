/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:51:36 by sechavez          #+#    #+#             */
/*   Updated: 2026/10/03 17:18:39 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	pq_init(t_pq *pq, int capacity)
{
	pq->heap = malloc(sizeof(t_req) * capacity);
	pq->size = 0;
	pq->capacity = capacity;
}

void	pq_free(t_pq *pq)
{
	if (pq->heap)
		free(pq->heap);
	pq->heap = NULL;
	pq->size = 0;
	pq->capacity = 0;
}

t_req	pq_peek(t_pq *pq)
{
	t_req	top;

	if (pq && pq->size > 0)
		return (pq->heap[0]);
	top.coder_id = -1;
	top.arrival_time = 0;
	top.deadline = 0;
	top.request_order = 0;
	return (top);
}
