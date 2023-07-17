#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

typedef struct s_philo
{	
	pthread_t **philo;
	pthread_t **timer;
	pthread_mutex_t **mutex;
	pthread_t *supervisor;
	
	int	n;
	int	tdie;
	int	teat;
	int	tsleep;
	int	neat;
	
	int *ready;
	int *thinking;
	int start;
	int death;
	
	int opt;
	int *eaten_enough;
	int *times_eaten;
	int all_have_eaten;
	
	
	

}				t_philo;

int			check_args(int argc, char **argv);
int			init_struct(int argc, char **argv, t_philo *philo);
int 		allocate_struct(t_philo *philo);
void		simulation(t_philo *philo);
long long 	get_time();
void		run_philo(t_philo *philo, int id);
void		timer(t_philo *philo, int id);
void 		free_struct(t_philo *philo);
void 		fill_ready(t_philo *philo);
void 		fill_thinking(t_philo *philo);
void 		fill_times_eaten(t_philo *philo);
void 		fill_eaten_enough(t_philo *philo);

int 		alloc_timer(t_philo *philo);
int			alloc_philo(t_philo *philo);
int			alloc_mutex(t_philo *philo);

void 		free_philo(t_philo *philo);
void 		free_timer(t_philo *philo);

int			p_think(t_philo *philo, int id, int *delay);
int			p_eat(t_philo *philo, int id);
int			p_sleep(t_philo *philo, int id);

int		grab_forks(t_philo *philo, int id);
int		release_forks(t_philo *philo, int id);

#endif