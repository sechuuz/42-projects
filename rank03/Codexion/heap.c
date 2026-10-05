/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:55:15 by sechavez          #+#    #+#             */
/*   Updated: 2026/10/03 17:18:39 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	is_higher_priority(t_req a, t_req b, t_sched sched)
{
	if (sched == SCHEDL_FIFO)
	{
		return (a.request_order < b.request_order);
	}
	if (a.deadline != b.deadline)
		return (a.deadline < b.deadline);
	if (a.arrival_time != b.arrival_time)
		return (a.arrival_time < b.arrival_time);
	return (a.coder_id < b.coder_id);
}

static void	sift_up(t_pq *pq, int idx, t_sched sched)
{
	t_req	tmp;
	int		parent;

	while (idx > 0)
	{
		parent = (idx - 1) / 2;
		if (is_higher_priority(pq->heap[idx], pq->heap[parent], sched))
		{
			tmp = pq->heap[idx];
			pq->heap[idx] = pq->heap[parent];
			pq->heap[parent] = tmp;
			idx = parent;
		}
		else
			break ;
	}
}

static void	sift_down(t_pq *pq, int idx, t_sched sched)
{
	int		smallest;
	int		left;
	int		right;
	t_req	tmp;

	while (idx < pq->size)
	{
		smallest = idx;
		left = 2 * idx + 1;
		right = 2 * idx + 2;
		if (left < pq->size
			&& is_higher_priority(pq->heap[left], pq->heap[smallest], sched))
			smallest = left;
		if (right < pq->size
			&& is_higher_priority(pq->heap[right], pq->heap[smallest], sched))
			smallest = right;
		if (smallest == idx)
			break ;
		tmp = pq->heap[idx];
		pq->heap[idx] = pq->heap[smallest];
		pq->heap[smallest] = tmp;
		idx = smallest;
	}
}

void	pq_insert(t_pq *pq, t_req req, t_sched sched)
{
	if (pq->size >= pq->capacity)
		return ;
	pq->heap[pq->size] = req;
	sift_up(pq, pq->size, sched);
	pq->size++;
}

t_req	pq_pop(t_pq *pq, t_sched sched)
{
	t_req	top;

	if (pq->size <= 0)
	{
		top.coder_id = -1;
		return (top);
	}
	top = pq->heap[0];
	pq->size--;
	if (pq->size > 0)
	{
		pq->heap[0] = pq->heap[pq->size];
		sift_down(pq, 0, sched);
	}
	return (top);
}
