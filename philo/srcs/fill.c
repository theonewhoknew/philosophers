#include "../inc/philo.h"

void fill_ready(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->n)
	{	
		philo->ready[i] = 0;
		i++;
	}
}

void fill_thinking(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->n)
	{	
		philo->thinking[i] = 0;
		i++;
	}
}

void fill_times_eaten(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->n)
	{	
		philo->times_eaten[i] = 0;
		i++;
	}
}

void fill_eaten_enough(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->n)
	{	
		philo->eaten_enough[i] = 0;
		i++;
	}
}