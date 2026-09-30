/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:09:21 by sechavez          #+#    #+#             */
/*   Updated: 2026/09/29 23:11:49 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static struct timespec	ms_to_timespec(long long target_ms)
{
	struct timespec	ts;

	ts.tv_sec = target_ms / 1000;
	ts.tv_nsec = (target_ms % 1000) * 1000000L;
	return (ts);
}

static void	wait_for_turn(t_dongle *d, t_coder *coder)
{
	long long		now;
	struct timespec	ts;

	while (is_simulation_active(coder->env))
	{
		now = get_time_ms();
		if (!d->is_taken && now >= d->available_at
			&& pq_peek(&d->queue).coder_id == coder->id)
			break ;
		if (!d->is_taken && now < d->available_at
			&& pq_peek(&d->queue).coder_id == coder->id)
		{
			ts = ms_to_timespec(d->available_at + 1);
			pthread_cond_timedwait(&d->cond, &d->mutex, &ts);
		}
		else
			pthread_cond_wait(&d->cond, &d->mutex);
	}
}

static void	acquire_one_dongle(t_dongle *d, t_coder *coder)
{
	t_req	req;

	pthread_mutex_lock(&d->mutex);
	req.coder_id = coder->id;
	req.arrival_time = get_time_ms();
	pthread_mutex_lock(&coder->state_mutex);
	req.deadline = coder->last_compile_start + coder->env->time_to_burnout;
	pthread_mutex_unlock(&coder->state_mutex);
	pq_insert(&d->queue, req, coder->env->scheduler);
	pthread_cond_broadcast(&d->cond);
	wait_for_turn(d, coder);
	if (is_simulation_active(coder->env))
	{
		pq_pop(&d->queue, coder->env->scheduler);
		d->is_taken = 1;
		pthread_cond_broadcast(&d->cond);
		print_state(coder->env, coder->id, "has taken a dongle");
	}
	pthread_mutex_unlock(&d->mutex);
}

void	acquire_dongles(t_coder *coder)
{
	int	first;
	int	second;

	if (coder->env->num_coders == 1)
	{
		acquire_one_dongle(&coder->env->dongles[0], coder);
		precise_sleep(coder->env->time_to_burnout + 10, coder->env);
		return ;
	}
	first = coder->left_dongle_id;
	second = coder->right_dongle_id;
	if (first > second)
	{
		first = coder->right_dongle_id;
		second = coder->left_dongle_id;
	}
	acquire_one_dongle(&coder->env->dongles[first], coder);
	acquire_one_dongle(&coder->env->dongles[second], coder);
}

void	release_dongles(t_coder *coder)
{
	t_dongle	*d1;
	t_dongle	*d2;
	long long	now;

	now = get_time_ms();
	d1 = &coder->env->dongles[coder->left_dongle_id];
	pthread_mutex_lock(&d1->mutex);
	d1->is_taken = 0;
	d1->available_at = now + coder->env->dongle_cooldown;
	pthread_cond_broadcast(&d1->cond);
	pthread_mutex_unlock(&d1->mutex);
	if (coder->env->num_coders == 1)
		return ;
	d2 = &coder->env->dongles[coder->right_dongle_id];
	pthread_mutex_lock(&d2->mutex);
	d2->is_taken = 0;
	d2->available_at = now + coder->env->dongle_cooldown;
	pthread_cond_broadcast(&d2->cond);
	pthread_mutex_unlock(&d2->mutex);
}