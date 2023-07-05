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
	pthread_mutex_t *forks;
	pthread_mutex_t id;
	pthread_t **philo;

}				t_philo;

int			check_args(int argc, char **argv);
void		init_struct(int argc, char **argv, t_philo *philo);
void		simulation(t_philo *philo);
long long 	get_timestamp();
void		run(t_philo *philo, int id);

#endif