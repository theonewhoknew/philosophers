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

static void	assign_args(int argc, char **argv, t_philo *philo)
{
	philo->n = ft_atoi(argv[1]);
	philo->tdie = ft_atoi(argv[2]);
	philo->teat = ft_atoi(argv[3]);
	philo->tsleep = ft_atoi(argv[4]);
}


int init_struct(int argc, char **argv, t_philo *philo)
{	
	assign_args(argc, argv, philo);
	philo->philo = NULL;
	philo->timer = NULL;
	philo->mutex = NULL;
	philo->ready = NULL;
	philo->thinking = NULL;
	if (argc == 6)
	{
		philo->opt = 1;
		philo->neat = ft_atoi(argv[5]);
		philo->all_have_eaten = 0;
		philo->times_eaten = NULL;
		philo->eaten_enough = NULL;
		philo->supervisor = NULL;
	}
	else
		philo->opt = 0;
	philo->death = 0;
	philo->start = 0;
	return (0);	
}