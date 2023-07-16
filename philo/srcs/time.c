#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/philo.h"

long long get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

static void	unlock(t_philo *philo, int id)
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

void timer(t_philo *philo, int id)
{	
	long long	og_time;
	int			elapsed;

	while (philo->simulation_start != 1)
		;
	while (philo->death != 1)
	{
		while (philo->thinking[id - 1] != 1)
			;
		og_time = get_time();
		while (philo->thinking[id - 1] == 1 && philo->death == 0)
		{	
			elapsed = get_time() - og_time;
			//printf("time to die: %d\n", philo->time_to_die);
			//printf("elapsed time: %d\n", elapsed);
			if (elapsed > philo->time_to_die)
			{	
				printf("%llu %d died\n", get_time(), id);
				philo->death = 1;
				unlock(philo, id);
			}
		}
	}
}
