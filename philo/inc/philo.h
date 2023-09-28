/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:06:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 12:20:49 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_param
{
	int				n;
	int				tdie;
	int				teat;
	int				tsleep;
	int				opt;
	int				max_iters;
	int				eaten;
	int				death;
	int				ready;
	int64_t			start;
	pthread_mutex_t	*fork;
}
			t_param;

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
int			init_philo(t_param *p, t_philo *philo);

int			check_args(int argc, char **argv);
void		simulation(t_param *param, t_philo *philo);
void		routine(void *arg);
void		free_struct(t_philo *philo);

void		fill_ready(t_philo *p);
void		fill_eating(t_philo *philo);
void		fill_times_eaten(t_philo *philo);
void		fill_eaten_enough(t_philo *philo);

void		free_philo(t_philo *philo);
void		free_timer(t_philo *philo);

void		*super_routine(void *arg);

void		p_eat(t_philo *philo);
void		p_sleep_think(t_philo *philo);

int			grab_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		release_all(t_param *param);

uint64_t	get_time(t_philo *philo);
uint64_t	get_start_time(void);
int			ft_usleep(useconds_t time);

void		check_threads(t_param *param, t_philo *philo);

#endif