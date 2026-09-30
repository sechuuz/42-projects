/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:47:39 by sechavez          #+#    #+#             */
/*   Updated: 2026/09/29 22:06:23 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	spawn_coders(t_env *env, int *created)
{
	int	i;

	i = 0;
	while (i < env->num_coders)
	{
		env->coders[i].last_compile_start = env->start_time;
		if (pthread_create(&env->coders[i].thread, NULL,
				coder_routine, &env->coders[i]) != 0)
			return (0);
		(*created)++;
		i++;
	}
	return (1);
}

static void	launch_simulation(t_env *env, int *created, int *monitor)
{
	env->start_time = get_time_ms();
	if (spawn_coders(env, created))
	{
		if (pthread_create(&env->monitor, NULL, monitor_routine, env) == 0)
			*monitor = 1;
	}
	if (!*monitor || *created < env->num_coders)
	{
		pthread_mutex_lock(&env->env_mutex);
		env->is_running = 0;
		pthread_mutex_unlock(&env->env_mutex);
	}
}

static void	join_threads(t_env *env, int created_coders, int monitor_created)
{
	int	i;

	if (monitor_created)
		pthread_join(env->monitor, NULL);
	i = 0;
	while (i < created_coders)
	{
		pthread_join(env->coders[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_env	env;
	int		created_coders;
	int		monitor_created;

	created_coders = 0;
	monitor_created = 0;
	memset(&env, 0, sizeof(t_env));
	if (!parse_args(&env, argc, argv) || !init_simulation(&env))
	{
		clean_all(&env);
		return (1);
	}
	launch_simulation(&env, &created_coders, &monitor_created);
	join_threads(&env, created_coders, monitor_created);
	clean_all(&env);
	return (0);
}
