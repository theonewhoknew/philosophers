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
		pthread_join(*(philo->timer[i]), NULL);
		i++;
	}
	pthread_join(*(philo->supervisor), NULL);
}

static void *super_routine(void *arg)
{	
	int i;
	t_philo *philo = (t_philo *)arg;
	int count;

	while (philo->death != 1 && philo->all_have_eaten != 1)
	{	
		i = 0;
		count = 0;
		while (i < philo->number_of_philo)
		{
			if (philo->eaten_enough[i] == 1)
				count++;
			i++;
		}
		if (count == philo->number_of_philo)
			philo->all_have_eaten = 1;
	}
}

static void *timer_routine(void *arg)
{
	static int id = 0;
	t_philo *philo = (t_philo *)arg;

	++id;
	timer(philo, id);
}

static void *philo_routine(void *arg)
{	
	static int id = 0;
	t_philo *philo = (t_philo *)arg;
	
	++id;
	run(philo, id);
}

void	simulation(t_philo *philo)
{
	int i;
	
	philo->philo = (pthread_t**)malloc(philo->number_of_philo * sizeof(pthread_t*));
	philo->timer = (pthread_t**)malloc(philo->number_of_philo * sizeof(pthread_t*));
	philo->mutex = (pthread_mutex_t**)malloc(philo->number_of_philo * sizeof (pthread_mutex_t*));
	i = 0;
	init_forks(philo);
	while (i < philo->number_of_philo)
	{	
		philo->philo[i] = (pthread_t*)malloc(sizeof (pthread_t));
		philo->timer[i] = (pthread_t*)malloc(sizeof (pthread_t));
		pthread_create(philo->philo[i], NULL, &philo_routine, philo);
		pthread_create(philo->timer[i], NULL, &timer_routine, philo);
		i++;
		usleep(1);
	}
	if (philo->opt_argument == 1)
			pthread_create(philo->supervisor, NULL, &super_routine, philo);
	wait_for_threads(philo);
}