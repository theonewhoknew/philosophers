#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void init_mutex(t_philo *philo)
{	
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{	
		philo->mutex[i] = (pthread_mutex_t*)malloc(sizeof (pthread_mutex_t));
		pthread_mutex_init(philo->mutex[i], NULL);
		i++;
	}
}

void	init_aux(t_philo *philo, char **argv)
{
	philo->ready = (int *)malloc(sizeof (int) * philo->number_of_philo);
	init_ready(philo);
	philo->thinking = (int *)malloc(sizeof (int) * philo->number_of_philo);
	init_thinking(philo);
	if (philo->opt_argument == 1)
	{	
		philo->number_of_eat = ft_atoi(argv[5]);
		philo->times_eaten = (int *)malloc(sizeof (int) * philo->number_of_philo);
		init_times_eaten(philo);
		philo->eaten_enough = (int *)malloc(sizeof (int) * philo->number_of_philo);
		init_eaten_enough(philo);
	}
	philo->all_have_eaten = 0;
}


void init_struct(int argc, char **argv, t_philo *philo)
{	
	if (argc == 6)
		philo->opt_argument = 1;
	else
		philo->opt_argument = 0;
	philo->number_of_philo = ft_atoi(argv[1]);
	philo->philo = (pthread_t**)malloc(philo->number_of_philo * sizeof (pthread_t*));
	philo->timer = (pthread_t**)malloc(philo->number_of_philo * sizeof (pthread_t*));
	philo->mutex = (pthread_mutex_t**)malloc(philo->number_of_philo * sizeof (pthread_mutex_t*));
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	init_aux(philo, argv);
	philo->death = 0;
	philo->simulation_start = 0;		
}