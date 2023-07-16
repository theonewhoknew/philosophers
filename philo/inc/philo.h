#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

typedef struct s_philo
{	
	pthread_t **philo;
	pthread_t **timer;
	pthread_t *supervisor;
	pthread_mutex_t **mutex;
	
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_eat;
	
	int *ready;
	int *thinking;
	int simulation_start;
	int death;
	
	int opt_argument;
	int *eaten_enough;
	int *times_eaten;
	int all_have_eaten;
	
	
	

}				t_philo;

int			check_args(int argc, char **argv);
void		init_struct(int argc, char **argv, t_philo *philo);
void		simulation(t_philo *philo);
long long 	get_time();
void		run(t_philo *philo, int id);
void		timer(t_philo *philo, int id);
void 		init_mutex(t_philo *philo);
void 		free_struct(t_philo *philo);
void 		unlock_mutex(t_philo *philo);
void 		init_ready(t_philo *philo);
void 		init_thinking(t_philo *philo);
void 		init_times_eaten(t_philo *philo);
void 		init_eaten_enough(t_philo *philo);

#endif