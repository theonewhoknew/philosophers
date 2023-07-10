#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

typedef struct s_philo
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_eat;
	pthread_mutex_t **mutex;
	int *forks;
	pthread_t **philo;
	pthread_t **timer;
	pthread_t *supervisor;
	int *times_eaten;
	int *eaten_enough;
	int all_have_eaten;
	int *ready;
	int simulation_start;
	int *thinking;
	int death;
	int opt_argument;

}				t_philo;

int			check_args(int argc, char **argv);
void		init_struct(int argc, char **argv, t_philo *philo);
void		simulation(t_philo *philo);
long long 	get_time();
void		run(t_philo *philo, int id);
void		timer(t_philo *philo, int id);
void		end_simulation(t_philo *philo);
void 		init_forks(t_philo *philo);

#endif