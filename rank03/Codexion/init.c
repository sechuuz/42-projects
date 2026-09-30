/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:26:28 by sechavez          #+#    #+#             */
/*   Updated: 2026/09/29 22:06:23 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	parse_scheduler(t_env *env, const char *str)
{
	if (strcmp(str, "fifo") == 0)
		env->scheduler = SCHEDL_FIFO;
	else if (strcmp(str, "edf") == 0)
		env->scheduler = SCHEDL_EDF;
	else
		return (0);
	return (1);
}

int	parse_args(t_env *env, int argc, char *argv[])
{
	if (argc != 9)
		return (0);
	env->num_coders = (int)safe_atoi(argv[1]);
	env->time_to_burnout = safe_atoi(argv[2]);
	env->time_to_compile = safe_atoi(argv[3]);
	env->time_to_debug = safe_atoi(argv[4]);
	env->time_to_refactor = safe_atoi(argv[5]);
	env->compiles_required = (int)safe_atoi(argv[6]);
	env->dongle_cooldown = safe_atoi(argv[7]);
	if (env->num_coders <= 0 || env->time_to_burnout <= 0
		|| env->time_to_compile <= 0 || env->time_to_debug <= 0
		|| env->time_to_refactor <= 0 || env->compiles_required < 0
		|| env->dongle_cooldown < 0)
		return (0);
	if (!parse_scheduler(env, argv[8]))
		return (0);
	return (1);
}

static int	init_dongles(t_env *env)
{
	int	i;

	env->dongles = malloc(sizeof(t_dongle) * env->num_coders);
	if (!env->dongles)
		return (0);
	i = 0;
	while (i < env->num_coders)
	{
		env->dongles[i].id = i;
		env->dongles[i].is_taken = 0;
		env->dongles[i].available_at = 0;
		if (pthread_mutex_init(&env->dongles[i].mutex, NULL) != 0)
			return (0);
		if (pthread_cond_init(&env->dongles[i].cond, NULL) != 0)
			return (0);
		pq_init(&env->dongles[i].queue, env->num_coders);
		if (!env->dongles[i].queue.heap)
			return (0);
		i++;
	}
	return (1);
}

int	init_simulation(t_env *env)
{
	int	i;

	env->is_running = 1;
	if (pthread_mutex_init(&env->env_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&env->print_mutex, NULL) != 0)
		return (0);
	if (!init_dongles(env))
		return (0);
	env->coders = malloc(sizeof(t_coder) * env->num_coders);
	if (!env->coders)
		return (0);
	i = 0;
	while (i < env->num_coders)
	{
		env->coders[i].id = i + 1;
		env->coders[i].left_dongle_id = i;
		env->coders[i].right_dongle_id = (i + 1) % env->num_coders;
		env->coders[i].compile_count = 0;
		env->coders[i].env = env;
		if (pthread_mutex_init(&env->coders[i].state_mutex, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	clean_all(t_env *env)
{
	int	i;

	i = 0;
	while (env->coders && i < env->num_coders)
	{
		pthread_mutex_destroy(&env->coders[i++].state_mutex);
		i++;
	}
	free(env->coders);
	i = 0;
	while (env->dongles && i < env->num_coders)
	{
		pthread_mutex_destroy(&env->dongles[i].mutex);
		pthread_cond_destroy(&env->dongles[i].cond);
		pq_free(&env->dongles[i].queue);
		i++;
	}
	free(env->dongles);
	pthread_mutex_destroy(&env->env_mutex);
	pthread_mutex_destroy(&env->print_mutex);
}
