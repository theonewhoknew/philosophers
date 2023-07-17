#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

static int	alloc_mutex(t_philo *philo)
{	
	int i;

	i = 0;
	while(i < philo->n)
	{	
		philo->mutex[i] = (pthread_mutex_t*)malloc(sizeof (pthread_mutex_t));
		if (philo->mutex[i] == NULL)
		{	
			--i;
			while (i >= 0)
			{
				free(philo->mutex[i]);
				--i;
			}
			return (1);
		}
		pthread_mutex_init(philo->mutex[i], NULL);
		i++;
	}
}

static int alloc_error(t_philo *philo)
{
	if (philo->philo != NULL)
		free(philo->philo);
	if (philo->timer != NULL)
		free(philo->timer);
	if (philo->mutex != NULL)
		free(philo->mutex);
	if (philo->ready != NULL)
		free(philo->ready);
	if (philo->thinking != NULL)
		free(philo->thinking);
	if (philo->opt == 1)
	{
		if (philo->times_eaten != NULL)
			free(philo->times_eaten);
		if (philo->eaten_enough != NULL)
			free(philo->eaten_enough);
	}
	return (1);
}

static int alloc_opt(t_philo *philo)
{
	if (philo->opt == 1)
	{
		philo->times_eaten = (int *)malloc(sizeof (int) * philo->n);
		if (philo->times_eaten == NULL)
			return (1);
		init_times_eaten(philo);
		philo->eaten_enough = (int *)malloc(sizeof (int) * philo->n);
		if (philo->eaten_enough == NULL)
			return (1);
		init_eaten_enough(philo);
		return (0);
	}
	else
		return (0);
}

int allocate_struct(t_philo *philo)
{	
	philo->philo = (pthread_t**)malloc(philo->n * sizeof (pthread_t*));
	if (philo->philo == NULL)
		return (alloc_error(philo));
	philo->timer = (pthread_t**)malloc(philo->n * sizeof (pthread_t*));
	if (philo->timer == NULL)
		return (alloc_error(philo));
	philo->mutex = (pthread_mutex_t**)malloc(philo->n * sizeof (pthread_mutex_t*));
	if (philo->mutex == NULL)
		return (alloc_error(philo));
	philo->ready = (int *)malloc(sizeof (int) * philo->n);
	if (philo->ready == NULL)
		return (alloc_error(philo));
	fill_ready(philo);
	philo->thinking = (int *)malloc(sizeof (int) * philo->n);
	if (philo->thinking == NULL)
		return (alloc_error(philo));
	fill_thinking(philo);
	if (alloc_opt(philo) == 1)
		return (alloc_error(philo));
	if (alloc_mutex(philo) == 1)
		return (alloc_error(philo));
	return (0);	
}