/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:26:36 by sechavez          #+#    #+#             */
/*   Updated: 2026/09/29 23:30:05 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long long	safe_atoi(const char *str)
{
	long long	res;
	int			i;

	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i] || str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res);
}

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	is_simulation_active(t_env *env)
{
	int	active;

	pthread_mutex_lock(&env->env_mutex);
	active = env->is_running;
	pthread_mutex_unlock(&env->env_mutex);
	return (active);
}

void	print_state(t_env *env, int coder_id, const char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&env->print_mutex);
	if (is_simulation_active(env) || strcmp(msg, "burned out") == 0)
	{
		timestamp = get_time_ms() - env->start_time;
		printf("%lld %d %s\n", timestamp, coder_id, msg);
	}
	pthread_mutex_unlock(&env->print_mutex);
}

void	precise_sleep(long long ms, t_env *env)
{
	long long	start;
	long long	elapsed;
	long long	rem;

	start = get_time_ms();
	while (is_simulation_active(env))
	{
		elapsed = get_time_ms() - start;
		if (elapsed >= ms)
			break ;
		rem = ms - elapsed;
		if (rem > 10)
			usleep((rem - 5) * 1000);
		else
			usleep(500);
	}
}