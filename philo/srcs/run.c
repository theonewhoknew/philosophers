#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

static void lock(t_philo *philo, int id)
{	
	if (id == 1)
	{	
		pthread_mutex_lock(philo->mutex[0]);
		pthread_mutex_lock(philo->mutex[philo->number_of_philo - 1]);
	}
	else
	{
		pthread_mutex_lock(philo->mutex[id - 1]);
		pthread_mutex_lock(philo->mutex[id - 2]);
	}
}

static void unlock(t_philo *philo, int id)
{
	if (id == 1)
	{
		pthread_mutex_unlock(philo->mutex[0]);
		pthread_mutex_unlock(philo->mutex[philo->number_of_philo - 1]);
	}
	else
	{
		pthread_mutex_unlock(philo->mutex[id - 1]);
		pthread_mutex_unlock(philo->mutex[id - 2]);
	}
}

static int all_ready(t_philo *philo)
{	
	int i;

	i = 0;
	while (philo->ready[i])
	{
		if (philo->ready[i] == 0)
			continue ;
		i++;
	}
	philo->simulation_start = 1;
	return (1);
}

void	run(t_philo *philo, int id)
{	
	long long time;

	philo->ready[id] = 1;
	while (all_ready(philo) != 1)
		;
	while (philo->death != 1 && philo->all_have_eaten != 1)
	{
		time = get_time();
		philo->thinking[id - 1] = 1;      // starts timer
		printf("%llu %d is thinking\n", time, id);
		lock(philo, id);
		time = get_time();
		philo->thinking[id - 1] = 0;   //stops timer
		printf("%llu %d is eating\n", time, id);
		usleep(philo->time_to_eat);
		if (philo->opt_argument == 1 && philo->eaten_enough[id - 1] != 1)
		{
			philo->times_eaten[id - 1]++;
			if (philo->times_eaten[id - 1] == philo->number_of_eat)
				philo->eaten_enough[id - 1] = 1;
		}
		unlock(philo, id);
		time = get_time();
		printf("%llu %d is sleeping\n", time, id);
		usleep(philo->time_to_sleep);
	}
}