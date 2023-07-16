#include "../inc/philo.h"

void init_ready(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{	
		philo->ready[i] = 0;
		i++;
	}
}

void init_thinking(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{	
		philo->thinking[i] = 0;
		i++;
	}
}

void init_times_eaten(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{	
		philo->times_eaten[i] = 0;
		i++;
	}
}

void init_eaten_enough(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{	
		philo->eaten_enough[i] = 0;
		i++;
	}
}