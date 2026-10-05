/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 00:00:00 by sechavez          #+#    #+#             */
/*   Updated: 2026/10/03 17:18:39 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	init_one_dongle(t_env *env, int index)
{
	t_dongle	*dongle;

	dongle = &env->dongles[index];
	dongle->id = index;
	dongle->is_taken = 0;
	dongle->available_at = 0;
	dongle->next_request_order = 0;
	if (pthread_mutex_init(&dongle->mutex, NULL) != 0)
		return (0);
	if (pthread_cond_init(&dongle->cond, NULL) != 0)
	{
		pthread_mutex_destroy(&dongle->mutex);
		return (0);
	}
	env->dongles_ready++;
	pq_init(&dongle->queue, env->num_coders);
	return (dongle->queue.heap != NULL);
}

static int	init_one_coder(t_env *env, int index)
{
	t_coder	*coder;

	coder = &env->coders[index];
	coder->id = index + 1;
	coder->left_dongle_id = index;
	coder->right_dongle_id = (index + 1) % env->num_coders;
	coder->compile_count = 0;
	coder->env = env;
	if (pthread_mutex_init(&coder->state_mutex, NULL) != 0)
		return (0);
	env->coders_ready++;
	return (1);
}

int	init_dongles(t_env *env)
{
	int	i;

	env->dongles = malloc(sizeof(t_dongle) * env->num_coders);
	if (!env->dongles)
		return (0);
	i = 0;
	while (i < env->num_coders)
	{
		if (!init_one_dongle(env, i))
			return (0);
		i++;
	}
	return (1);
}

int	init_coders(t_env *env)
{
	int	i;

	env->coders = malloc(sizeof(t_coder) * env->num_coders);
	if (!env->coders)
		return (0);
	i = 0;
	while (i < env->num_coders)
	{
		if (!init_one_coder(env, i))
			return (0);
		i++;
	}
	return (1);
}

void	release_one_dongle(t_env *env, int dongle_id, long long now)
{
	t_dongle	*dongle;

	dongle = &env->dongles[dongle_id];
	pthread_mutex_lock(&dongle->mutex);
	dongle->is_taken = 0;
	dongle->available_at = now + env->dongle_cooldown;
	pthread_cond_broadcast(&dongle->cond);
	pthread_mutex_unlock(&dongle->mutex);
}
