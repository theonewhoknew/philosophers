
#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

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
	if (philo->eating != NULL)
		free(philo->eating);
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
		fill_times_eaten(philo);
		philo->eaten_enough = (int *)malloc(sizeof (int) * philo->n);
		if (philo->eaten_enough == NULL)
			return (1);
		fill_eaten_enough(philo);
		return (0);
	}
	else
		return (0);
}

static int	philo_timer_mutex(t_philo *philo)
{
	if (alloc_philo(philo) == 1)
		return (1);
	if (alloc_timer(philo) == 1)
	{	
		free_philo(philo);
		return (1);
	}
	if (alloc_mutex(philo) == 1)
	{
		free_philo(philo);
		free_timer(philo);
		return (1);
	}
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
	philo->eating = (int *)malloc(sizeof (int) * philo->n);
	if (philo->eating == NULL)
		return (alloc_error(philo));
	fill_eating(philo);
	if (alloc_opt(philo) == 1)
		return (alloc_error(philo));
	if (philo_timer_mutex(philo) == 1)
		return (alloc_error(philo));
	return (0);	
}