/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:06:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/29 10:29:20 by theonewhokn      ###   ########.fr       */
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
}				t_param;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				thread_start;
	int				iters;
	int64_t			last_meal;
	t_param			*par;
	pthread_t		philo_thread;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;

}				t_philo;

int			init_params(int argc, char **argv, t_param *param);
t_philo		*init_philo(t_param *p, t_philo *philo);

int			check_args(int argc, char **argv);
void		simulation(t_param *param, t_philo *philo);
void		*routine(void *arg);
void		free_struct(t_philo *philo);

void		free_philo(t_philo *philo);
void		free_timer(t_philo *philo);

int			grab_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		release_all(t_param *param);

int64_t		get_time(t_param *param);
int64_t		get_start_time(void);
int			ft_usleep(int64_t time);

void		check_threads(t_param *param, t_philo *philo);

void		print_params(t_param *param);
void		print_state(t_philo *philo, int type);

#endif