/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:06:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 10:33:35 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_philo
{
	pthread_t		**p;
	pthread_t		**t;
	pthread_mutex_t	**m;
	pthread_t		*s;
	uint64_t		s_t;
	int				n;
	int				start;
	int				tdie;
	int				teat;
	int				tsleep;
	int				neat;
	int				*eating;
	int				death;
	int				opt;
	int				*ready;
	int				*eaten_enough;
	int				*times_eaten;
	int				eaten;
}				t_philo;

int			check_args(int argc, char **argv);
int			init_struct(int argc, char **argv, t_philo *philo);
int			allocate_struct(t_philo *philo);
void		simulation(t_philo *philo);
void		run_philo(t_philo *philo, int id);
void		timer(t_philo *philo, int id);
void		free_struct(t_philo *philo);

void		fill_ready(t_philo *p);
void		fill_eating(t_philo *philo);
void		fill_times_eaten(t_philo *philo);
void		fill_eaten_enough(t_philo *philo);

int			alloc_timer(t_philo *philo);
int			alloc_philo(t_philo *philo);
int			alloc_mutex(t_philo *philo);

void		free_philo(t_philo *philo);
void		free_timer(t_philo *philo);

void		*super_routine(void *arg);

int			p_think(t_philo *philo, int id, int *delay);
int			p_eat(t_philo *philo, int id);
int			p_sleep(t_philo *philo, int id);

int			grab_forks(t_philo *philo, int id);
void		release_forks(t_philo *philo, int id);
void		release_all(t_philo *philo);

uint64_t	get_time(t_philo *philo);
uint64_t	get_start_time(void);
int			ft_usleep(useconds_t time);

#endif