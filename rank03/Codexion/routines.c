/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:38:47 by sechavez          #+#    #+#             */
/*   Updated: 2026/10/03 18:55:50 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	check_burnout(t_env *env, t_coder *coder, long long now)
{
	int	burned;

	burned = 0;
	pthread_mutex_lock(&coder->state_mutex);
	if (now - coder->last_compile_start > env->time_to_burnout)
		burned = 1;
	pthread_mutex_unlock(&coder->state_mutex);
	if (burned)
	{
		print_state(env, coder->id, "burned out");
		stop_simulation(env);
	}
	return (burned);
}

static int	check_goal(t_env *env)
{
	int	i;
	int	all_done;

	all_done = 1;
	i = 0;
	while (i < env->num_coders)
	{
		pthread_mutex_lock(&env->coders[i].state_mutex);
		if (env->coders[i].compile_count < env->compiles_required)
			all_done = 0;
		pthread_mutex_unlock(&env->coders[i].state_mutex);
		i++;
	}
	if (all_done)
		stop_simulation(env);
	return (all_done);
}

void	*monitor_routine(void *arg)
{
	t_env		*env;
	int			i;
	long long	now;

	env = (t_env *)arg;
	while (is_simulation_active(env))
	{
		now = get_time_ms();
		i = 0;
		while (i < env->num_coders)
		{
			if (check_burnout(env, &env->coders[i], now))
				return (NULL);
			i++;
		}
		if (check_goal(env))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}

static void	execute_compile_cycle(t_coder *coder)
{
	if (!acquire_dongles(coder))
		return ;
	pthread_mutex_lock(&coder->state_mutex);
	coder->last_compile_start = get_time_ms();
	pthread_mutex_unlock(&coder->state_mutex);
	print_state(coder->env, coder->id, "is compiling");
	precise_sleep(coder->env->time_to_compile, coder->env);
	release_dongles(coder);
	if (!is_simulation_active(coder->env))
		return ;
	pthread_mutex_lock(&coder->state_mutex);
	coder->compile_count++;
	pthread_mutex_unlock(&coder->state_mutex);
	release_dongles(coder);
	if (!is_simulation_active(coder->env))
		return ;
	print_state(coder->env, coder->id, "is debugging");
	precise_sleep(coder->env->time_to_debug, coder->env);
	if (!is_simulation_active(coder->env))
		return ;
	print_state(coder->env, coder->id, "is refactoring");
	precise_sleep(coder->env->time_to_refactor, coder->env);
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	if (coder->id % 2 == 0)
		precise_sleep(coder->env->time_to_compile, coder->env);
	while (is_simulation_active(coder->env))
		execute_compile_cycle(coder);
	return (NULL);
}
