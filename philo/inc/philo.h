/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:06:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/02 12:56:19 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>

# define EAT	1
# define SLEEP	2
# define THINK	3
# define FORK	4
# define DIE	5
# define ITERS	6
# define DEBUG	7

typedef struct s_param
{
	int				n;
	int				tdie;
	int				teat;
	int				tsleep;
	int				max_iters;
	int				end;
	int				ready;
	int64_t			start;
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_end;
	pthread_mutex_t	m_ready;
	pthread_mutex_t	m_start;
}				t_param;

typedef struct s_philo
{
	int				id;
	int				iters;
	int				ready;
	int64_t			last;
	t_param			*par;
	pthread_t		philo_thread;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	m_last;
	pthread_mutex_t	m_iters;

}				t_philo;

int			check_args(int argc, char **argv);
int			init_params(int argc, char **argv, t_param *param);
t_philo		*init_philo(t_param *p, t_philo *philo);

void		simulation(t_param *param, t_philo *philo);
void		*routine(void *arg);
void		check_threads(t_param *param, t_philo *philo);

int			grab_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		release_all(t_param *param);

int64_t		get_time(t_param *param);
int64_t		get_start_time(void);
int			ft_usleep(int64_t time);

void		print_params(t_param *param);
void		print_state(t_philo *philo, int type);

#endif