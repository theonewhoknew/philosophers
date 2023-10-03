/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:06:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/03 13:04:26 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>

# define DIE	1
# define ITERS	2

typedef struct s_param
{
	int				n;
	int				tdie;
	int				teat;
	int				tsleep;
	int				max_iters;
	int				end;
	int				ready;
	int				start;
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
	int				last;
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
int			release_forks(t_philo *philo, int ret);
void		release_all(t_param *param);

int			get_time(t_param *param);
int			get_start_time(void);
int			ft_usleep(int time, t_param *param);

int			print_eat(t_philo *philo);
int			print_sleep(t_philo *philo);
int			print_think(t_philo *philo);
int			print_fork(t_philo *philo);
int			print_end(t_philo *philo, int type);

void		print_aux(int64_t ms, int id, char *str);
int			check_death(t_philo *philo);

#endif