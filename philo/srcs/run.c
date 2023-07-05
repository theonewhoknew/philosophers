#include "../inc/philo.h"
#include <unistd.h>
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

void	run(t_philo *philo, int id)
{	
	long long time;

	time = get_time();
	printf("%llu %d is thinking\n", time, id);
	lock(philo, id);
	time = get_time();
	printf("%llu %d is eating\n", time, id);
	usleep(philo->time_to_eat);
	unlock(philo, id);
	time = get_time();
	printf("%llu %d is sleeping\n", time, id);
	usleep(philo->time_to_sleep);
}