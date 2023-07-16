#include "../inc/philo.h"
#include <stdlib.h>
#include <stdio.h>

static void	free_mutex(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{
		pthread_mutex_destroy(philo->mutex[i]);
		i++;
	}
	i = 0;
	while(i < philo->number_of_philo)
	{
		free(philo->mutex[i]);
		i++;
	}
	free(philo->mutex);
}

static void free_philo(t_philo *philo)
{	
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{
		free(philo->philo[i]);
		i++;
	}
	free(philo->philo);
}

static void free_timer(t_philo *philo)
{	
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{
		free(philo->timer[i]);
		i++;
	}
	free(philo->timer);
}

void free_struct(t_philo *philo)
{	
	free_philo(philo);
	free_timer(philo);
	free_mutex(philo);
	free(philo->ready);
	free(philo->thinking);
	if (philo->opt_argument == 1)
	{
		free(philo->supervisor);
		free(philo->times_eaten);
		free(philo->eaten_enough);
	}
}