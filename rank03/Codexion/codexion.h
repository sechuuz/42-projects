/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 20:04:33 by sechavez          #+#    #+#             */
/*   Updated: 2026/10/03 18:21:03 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef enum e_sched
{
	SCHEDL_FIFO,
	SCHEDL_EDF
}	t_sched;

typedef struct s_req
{
	int			coder_id;
	long long	arrival_time;
	long long	deadline;
	long long	request_order;
}	t_req;

typedef struct s_pq
{
	t_req	*heap;
	int		size;
	int		capacity;
}	t_pq;

typedef struct s_dongle
{
	int				id;
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	int				is_taken;
	long long		available_at;
	long long		next_request_order;
	t_pq			queue;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	pthread_t		thread;
	int				left_dongle_id;
	int				right_dongle_id;
	int				compile_count;
	long long		last_compile_start;
	pthread_mutex_t	state_mutex;
	struct s_env	*env;
}	t_coder;

typedef struct s_env
{
	int				num_coders;
	long long		time_to_burnout;
	long long		time_to_compile;
	long long		time_to_debug;
	long long		time_to_refactor;
	int				compiles_required;
	long long		dongle_cooldown;
	t_sched			scheduler;

	long long		start_time;
	int				is_running;
	pthread_mutex_t	env_mutex;
	pthread_mutex_t	print_mutex;

	t_dongle		*dongles;
	t_coder			*coders;
	pthread_t		monitor;

	int				env_inited;
	int				print_inited;
	int				dongles_ready;
	int				coders_ready;
}	t_env;

long long	get_time_ms(void);
int			precise_sleep(long long ms, t_env *env);
void		print_state(t_env *env, int coder_id, const char *msg);
int			is_simulation_active(t_env *env);
long long	safe_atoi(const char *str);

void		pq_init(t_pq *pq, int capacity);
void		pq_insert(t_pq *pq, t_req req, t_sched sched);
t_req		pq_peek(t_pq *pq);
t_req		pq_pop(t_pq *pq, t_sched sched);
void		pq_free(t_pq *pq);

int			parse_args(t_env *env, int argc, char **argv);
int			init_simulation(t_env *env);
int			init_dongles(t_env *env);
int			init_coders(t_env *env);
void		release_one_dongle(t_env *env, int dongle_id, long long now);
void		clean_all(t_env *env);
void		stop_simulation(t_env *env);

void		*coder_routine(void *arg);
void		*monitor_routine(void *arg);

int			acquire_dongles(t_coder *coder);
void		release_dongles(t_coder *coder);

#endif
