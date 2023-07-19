#include "../inc/philo.h"
#include <stdio.h>

static int	all_ready(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		if (philo->ready[i] == 1)
			i++;
	}
	philo->start = 1;
	return (1);
}

void	*super_routine(void *arg)
{
	int	i;
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	while (all_ready(philo) != 1)
		;
	if (philo->opt == 1)
	{
		while (philo->death != 1 && philo->all_have_eaten != 1)
		{
			i = 0;
			while (i < philo->n && philo->death != 1)
			{
				if (philo->eaten_enough[i] == 1)
				{
					++i;
				}
			}
			philo->all_have_eaten = 1;
		}
	}
}
