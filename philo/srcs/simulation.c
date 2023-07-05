#include "../inc/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void *philo_routine(void *arg)
{	
	t_philo *philo = (t_philo *)arg;
	think(philo);

}

static void create_philo(t_philo *philo)
{
	int i;
	t_philo **philo_id;

	philo_id = (t_philo**)malloc(philo->number_of_philo * sizeof (t_philo*));
	i = 0;
	while (i < philo->number_of_philo)
	{	
		philo->philo[i] = (pthread_t*)malloc(sizeof (pthread_t));
		philo_id[i] = (t_philo*)malloc(sizeof (t_philo));
		*philo_id[i] = *philo;
		philo_id[i]->thread_id = i + 1;
		pthread_create(philo->philo[i], NULL, &philo_routine, philo_id[i]);
		i++;
	}
}

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

void	simulation(t_philo *philo)
{	
	philo->philo = (pthread_t**)malloc(philo->number_of_philo * sizeof(pthread_t*));
	create_philo(philo);
	wait_for_threads(philo);
	
}