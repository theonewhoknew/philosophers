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

void init_struct(int argc, char **argv, t_philo *philo)
{	
	int i;

	philo->number_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]) * 1000;
	philo->time_to_eat = ft_atoi(argv[3]) * 1000;
	philo->time_to_sleep = ft_atoi(argv[4]) * 1000;
	philo->death = 0;
	philo->forks = (int *)malloc(sizeof (int) * philo->number_of_philo);
	i = 0;
	while (i < philo->number_of_philo)
	{
		philo->forks[i] = 0;
		i++;
	}
	if (argc == 6)
		philo->number_of_eat = ft_atoi(argv[5]);
	else
		philo->number_of_eat = -1;
}