#include "../inc/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static	void wait_for_threads(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->number_of_philo)
	{	
		pthread_join(*(philo->philo[i]), NULL);
		i++;
	}
}

void *philo_routine(void *arg)
{	
	static int id = 0;
	t_philo *philo = (t_philo *)arg;
	
	++id;
	run(philo, id);
}

static void init_simulation(t_philo *philo)
{
	int i;
	philo->philo = (pthread_t**)malloc(philo->number_of_philo * sizeof(pthread_t*));

	i = 0;
	while (i < philo->number_of_philo)
	{	
		philo->philo[i] = (pthread_t*)malloc(sizeof (pthread_t));
		pthread_create(philo->philo[i], NULL, &philo_routine, philo);
		i++;
		usleep(100);
	}
}

void	simulation(t_philo *philo)
{
	init_simulation(philo);
	wait_for_threads(philo);
	
}